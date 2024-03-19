#include "groupchats.h"
#include "ui_groupchats.h"
#include "homepage.h"
#include "settings.h"
#include "groups.h"
#include "accounts.h"
#include "QTimer"
#include "QDateTime"
#include "global_variables.hpp"
#include "project_database.h"
#include "existingchats.h"
#include "adminmanageusers.h"
#include "adminmanagegroups.h"
#include "adminmanagemods.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QtWidgets/QMessageBox>

GroupChats::GroupChats(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GroupChats)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));


    ui->logoff_button->setIcon(QIcon("logoff.png"));
    ui->logoff_button->setIconSize(QSize(45, 50));

    ui->account_name->setText(current_user);
    ui->set_group_name->setPlaceholderText("Enter group name: ");
    ui->profile_pic->setPixmap(QPixmap::fromImage(image).scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation));

    check_account_type();
    set_accessibility_settings();

    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    load_user_accounts();

    if(current_user != "username")
    {
        QTimer *update;
        update = new QTimer();
        QObject::connect(update, SIGNAL(timeout()),this, SLOT(update_date_time()));
        update->start(100);

        QTimer *check_user_type;
        check_user_type = new QTimer();
        QObject::connect(check_user_type, SIGNAL(timeout()),this, SLOT(check_account_type()));
        check_user_type->start(100000);

        inactivity_timer = new QTimer();
        QObject::connect(inactivity_timer, SIGNAL(timeout()),this, SLOT(update_inactivity_status()));
        inactivity_timer->start(1000);
    }

    inactive_seconds = 0;
    inactive_minutes = 0;
}

GroupChats::~GroupChats()
{
    delete ui;
}

void GroupChats::update_inactivity_status()
{
    inactive_seconds += 1;
    if(inactive_seconds == 60)
    {
        inactive_seconds = 0;
        inactive_minutes += 1;
    }

    if(inactive_minutes == 15)
    {
        inactive_seconds = 0;
        inactive_minutes = 0;
        inactivity_timer->stop();
        on_logoff_button_clicked();
    }
}

void GroupChats::keyPressEvent(QKeyEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void GroupChats::mousePressEvent(QMouseEvent *event) {
    inactive_seconds = 0;
    inactive_minutes = 0;
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void GroupChats::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void GroupChats::update_date_time()
{
     ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void GroupChats::check_account_type(){
    if (current_account_type == "User"){
        account_checked = true;
        ui->manage_users_button->hide();
        ui->manage_groups_button->hide();
        ui->manage_mods_button->hide();
    }
    else if(current_account_type == "Mod") {
        account_checked = true;
        ui->manage_users_button->show();
        ui->manage_groups_button->show();
        ui->manage_mods_button->show();
    }
}

void GroupChats::load_user_accounts()
{
    if(database.open())
    {
        QSqlQuery query(QSqlDatabase::database(DB_NAME));
        QString sql_sentence = "SELECT username FROM ";
        sql_sentence += TB_USERS;
        sql_sentence += " WHERE username NOT LIKE :username AND user_id NOT LIKE 1"; //user_id 1 is the id for the admin account

        query.prepare(sql_sentence);
        query.bindValue(":username", current_user);

        query.exec();

        ui->add_remove_user_table->setColumnCount(3);

        QStringList labels;
        labels << "Add User" << "Username" << "Moderator";
        ui->add_remove_user_table->setHorizontalHeaderLabels(labels);

        int rowCount = 0;
        while (query.next())
        {
            ui->add_remove_user_table->insertRow(rowCount);
            QTableWidgetItem *add_user_checkbox = new QTableWidgetItem;
            QTableWidgetItem *username = new QTableWidgetItem;
            QTableWidgetItem *user_is_moderator = new QTableWidgetItem;

            username->setText(query.value(0).toString());

            add_user_checkbox->setCheckState(Qt::Unchecked);
            user_is_moderator->setCheckState(Qt::Unchecked);

            ui->add_remove_user_table->setItem(rowCount, 0, add_user_checkbox);
            ui->add_remove_user_table->setItem(rowCount, 1, username);
            ui->add_remove_user_table->setItem(rowCount, 2, user_is_moderator);

            rowCount ++;

        }
        query.finish();
    }

    database.close();
}

void GroupChats::on_create_group_button_clicked()
{
    inactive_seconds = 0;
    inactive_minutes = 0;

    int addUsers = 1;
    int rowCount = 0;
    int groupchat_id;
    int boxChecked;

    QString group_name = ui->set_group_name->text();

    while(ui->add_remove_user_table->item(rowCount, 0))
    {
        boxChecked = ui ->add_remove_user_table->item(rowCount, 0)->checkState();
        if (boxChecked == 2)
        {
            addUsers ++;
        }
        rowCount ++;
    }
    if (group_name != "" && addUsers > 2)
    {
        if (database.open())
        {
            QSqlQuery query;
            QString sql_sentence = "INSERT INTO ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += " (groupchat_name) VALUES (:groupchat_name)";
            query.prepare(sql_sentence);

            query.bindValue(":groupchat_name", group_name);

            if (query.exec())
            {
                QString user_type = "User";
                int user_id;
                bool usersAdded = false;

                QMessageBox::information(this, "Inserted", "Groupchat has been made");
                query.finish();

                //Getting the id of the group thats been made so users can be added
                sql_sentence = "SELECT groupchat_id FROM ";
                sql_sentence += TB_GROUPCHATS;
                sql_sentence += " WHERE groupchat_name = :groupchat_name";
                query.prepare(sql_sentence);

                query.bindValue(":groupchat_name", group_name);



                if (query.exec())
                {
                    if(query.next())
                    {
                        groupchat_id = query.value(0).toInt();
                    }

                    query.finish();

                    rowCount = 0;

                    //NEED TO CREATE LOOP HERE TO ADD ALL THE CHECKED USERS INTO THE GROUP
                    while(ui->add_remove_user_table->item(rowCount, 0))
                    {
                        boxChecked = ui->add_remove_user_table->item(rowCount, 0)->checkState();

                        if(boxChecked == 2)
                        {
                            QString add_user = ui->add_remove_user_table->item(rowCount, 1)->text();



                            sql_sentence = "SELECT user_id FROM ";
                            sql_sentence += TB_USERS;
                            sql_sentence += " WHERE username = :username";
                            query.prepare(sql_sentence);


                            query.bindValue(":username", add_user);

                            query.exec();

                            if(query.next())
                            {
                                user_id = query.value(0).toInt();

                                query.finish();

                                boxChecked = ui->add_remove_user_table->item(rowCount, 2)->checkState();
                                if(boxChecked == 2)
                                {
                                    user_type = "Mod";
                                }
                                else
                                {
                                    user_type = "User";
                                }

                                upload_to_database(groupchat_id, user_id, user_type);

                            }
                        }
                        rowCount++;
                        usersAdded = true;
                    }
                }

                if(usersAdded == true)
                {
                    user_type = "Admin";

                    sql_sentence = "SELECT user_id FROM ";
                    sql_sentence += TB_USERS;
                    sql_sentence += " WHERE username = :username";
                    query.prepare(sql_sentence);


                    query.bindValue(":username", current_user);

                    query.exec();

                    if(query.next())
                    {
                        user_id = query.value(0).toInt();

                        query.finish();

                    }

                    upload_to_database(groupchat_id, user_id, user_type);
                }

            }
            else
            {
                QMessageBox::information(this, "NOT Inserted", "A groupchat with that name already exists");
            }

            database.close();
        }
    }

    hide(); // the mainwindow (login page) is hidden
    Groups *groups; // declare the register page
    groups = new Groups(this);
    groups->show(); // show the register page
}

void GroupChats::upload_to_database(int group_id, int user_id, QString user_type)
{
    if(database.open())
    {
        QSqlQuery insert_user_data;
        QString sql_sentence;

        sql_sentence += "INSERT INTO ";
        sql_sentence += TB_GROUPMEMBERS;
        sql_sentence += " (group_id, user_id, user_type) VALUES (:group_id, :user_id, :user_type)";
        insert_user_data.prepare(sql_sentence);

        insert_user_data.bindValue(":group_id", group_id);
        insert_user_data.bindValue(":user_id", user_id);
        insert_user_data.bindValue(":user_type", user_type);


        insert_user_data.exec();
    }
}

void GroupChats::on_home_button_clicked()
{
    inactivity_timer->stop();
    hide();
    HomePageNewest *home_page_newest;
    home_page_newest = new HomePageNewest(this);
    home_page_newest->show();
}

void GroupChats::on_chats_button_clicked()
{
    inactivity_timer->stop();
    hide();
    ExistingChats *existing_chats;
    existing_chats = new ExistingChats(this);
    existing_chats->show();
}

void GroupChats::on_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Groups *groups;
    groups = new Groups(this);
    groups->show();
}

void GroupChats::on_accounts_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Accounts *accounts;
    accounts = new Accounts(this);
    accounts->show();
}

void GroupChats::on_settings_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Settings *settings;
    settings = new Settings(this);
    settings->show();
}

void GroupChats::on_manage_users_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageUsers *admin_m_users;
    admin_m_users = new  AdminManageUsers(this);
    admin_m_users->show();
}

void GroupChats::on_manage_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();
}

void GroupChats::on_manage_mods_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageMods *admin_m_mods;
    admin_m_mods = new  AdminManageMods(this);
    admin_m_mods->show();
}

void GroupChats::on_shutdown_button_clicked()
{
    inactivity_timer->stop();
    if(database.open())
    {
        QSqlQuery sql_update_query(QSqlDatabase::database(DB_NAME));
        QString sql_shutdown_query = "UPDATE ";
        sql_shutdown_query += TB_USERS;
        sql_shutdown_query += " SET active_status = 'Offline'";
        sql_shutdown_query += "WHERE username = '" + current_user + "'";

        sql_update_query.prepare(sql_shutdown_query);
        if(sql_update_query.exec(sql_shutdown_query)){
            QCoreApplication::exit();
        }
        else{
             QMessageBox::warning(this,"Error","Failed to shutdown");
        }
        sql_update_query.finish();
    }
    else
    {
        QMessageBox::warning(this,"Error","Database is not connected");
    }
    database.close();
}

void GroupChats::on_logoff_button_clicked()
{
    inactivity_timer->stop();
    if(database.open())
    {
        QSqlQuery sql_update_query(QSqlDatabase::database(DB_NAME));
        QString sql_logout_query = "UPDATE ";
        sql_logout_query += TB_USERS;
        sql_logout_query += " SET active_status = 'Offline' ";
        sql_logout_query += "WHERE username = '" + current_user + "'";

        sql_update_query.prepare(sql_logout_query);
        if(sql_update_query.exec(sql_logout_query)){
            hide();
            MainWindow *main_window;
            main_window = new MainWindow(this);
            main_window->show();
        }
        else{
            QMessageBox::warning(this,"Error","Failed to log out" + current_user);
        }
        sql_update_query.finish();
    }
    else
    {
        QMessageBox::warning(this,"Error","Database is not connected");
    }
    database.close();
}

void GroupChats::on_add_remove_user_table_cellClicked(int row, int column)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void GroupChats::on_set_group_name_cursorPositionChanged(int arg1, int arg2)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void GroupChats::set_accessibility_settings()
{
    if(dark_mode_toggle == "Dark"){
        QString white_colour = "white";
        QString grey_colour = "Grey";
        QString dim_grey_colour = "DimGrey";
        QString light_grey_colour = "lightGrey";

        ui->central_widget->setStyleSheet("#central_widget { background-color: " + grey_colour + ";}");
        ui->page_name_widget->setStyleSheet("#page_name_widget { background-color: " + grey_colour + "}");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: " + white_colour + ";\n	font-size: 50px;\n}");
        ui->sidebar->setStyleSheet("#sidebar { background-color: "+ grey_colour + ";border-radius: 8px;} "
                                   "QLabel { color: " + white_colour + "; } "
                                   "QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_groups_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_mods_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_users_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget { background-color: " + grey_colour + ";}");
    }

    else if (dark_mode_toggle == "Light"){
        ui->central_widget->setStyleSheet("");
        ui->page_name_widget->setStyleSheet("");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: DimGrey;\n	font-size: 50px;\n}");
        ui->sidebar->setStyleSheet("#sidebar { background-color: LightGrey;border-radius: 8px;} "
                                   "QLabel { color: white; } "
                                   "QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->page_contents_widget->setStyleSheet("");
    }
}

