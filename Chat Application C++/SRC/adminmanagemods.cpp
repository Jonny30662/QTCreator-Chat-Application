#include "adminmanagemods.h"
#include "ui_adminmanagemods.h"
#include "adminmanagegroups.h"
#include "adminhome.h"
#include "adminmanageusers.h"
#include "global_variables.hpp"
#include "project_database.h"
#include "homepage.h"
#include "mainwindow.h"

#include <QMessageBox>

QString selected_mod;
AdminManageMods::AdminManageMods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminManageMods)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->promote_button->setEnabled(false);
    ui->demote_button->setEnabled(false);
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));


    ui->logoff_button->setIcon(QIcon("logoff.png"));
    ui->logoff_button->setIconSize(QSize(45, 50));

    ui->account_name->setText(current_user);
    ui->profile_pic->setPixmap(QPixmap::fromImage(image).scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation));

    readDBandDisplayTable();
    check_account_type();
    set_accessibility_settings();

    if(current_user != "username")
    {
        QTimer *update;
        update = new QTimer();
        QObject::connect(update, SIGNAL(timeout()),this, SLOT(update_date_time()));
        update->start(100);

        QTimer *account_type;
        account_type = new QTimer();
        QObject::connect(account_type, SIGNAL(timeout()),this, SLOT(check_account_type()));
        account_type->start(100000);

        inactivity_timer = new QTimer();
        QObject::connect(inactivity_timer, SIGNAL(timeout()),this, SLOT(update_inactivity_status()));
        inactivity_timer->start(1000);
    }

    inactive_seconds = 0;
    inactive_minutes = 0;
}

AdminManageMods::~AdminManageMods()
{
    delete ui;
}

void AdminManageMods::update_inactivity_status()
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

void AdminManageMods::keyPressEvent(QKeyEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void AdminManageMods::mousePressEvent(QMouseEvent *event) {
    inactive_seconds = 0;
    inactive_minutes = 0;
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void AdminManageMods::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void AdminManageMods::update_date_time()
{
    ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void AdminManageMods::check_account_type(){
    if (current_account_type == "Admin"){
        account_checked = true;
        ui->main_menu_button->hide();
    }
    else if(current_account_type == "Mod") {
        account_checked = true;
        ui->main_menu_button->show();
    }
}

void AdminManageMods::readDBandDisplayTable()
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    if(!database.open()){
        QMessageBox::warning(this,"Error","Database is not connected");
        return;
    }

    QSqlQuery sql_select_mods_query(database);
    QString sql_display_mods_query = "SELECT chat_users.user_id, chat_users.username, chat_users.account_type FROM ";
    sql_display_mods_query += TB_USERS;
    sql_display_mods_query += " WHERE chat_users.account_type NOT LIKE 'Admin' ";
    sql_display_mods_query += "AND username NOT LIKE '" + current_user + "'";
    sql_display_mods_query += " ORDER BY chat_users.user_id;";

    if(!sql_select_mods_query.exec(sql_display_mods_query)){
        QMessageBox::warning(this,"Error","Failed to display mods");
        return;
    }

    ui->tableWidget->setColumnCount(5);
    QStringList labels;
    labels << "User ID" << "Profile Picture"  << "Username"  << "User Type" << "";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    int rowCount = 0;
    while(sql_select_mods_query.next()){
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *image = new QTableWidgetItem;
        QTableWidgetItem *userID = new QTableWidgetItem;
        QTableWidgetItem *username = new QTableWidgetItem;
        QTableWidgetItem *userType = new QTableWidgetItem;

        userID->setText(sql_select_mods_query.value(0).toString());
        username->setText(sql_select_mods_query.value(1).toString());
        userType->setText(sql_select_mods_query.value(2).toString());

        QModelIndex index;
        QSqlQueryModel model;
        QByteArray bytes;
        QSqlQuery sql_image_query(database);

        QString user = sql_select_mods_query.value(1).toString();
        QString sql_display_image_query = "SELECT image FROM ";
        sql_display_image_query += TB_USERS;
        sql_display_image_query += " WHERE username = '" + user + "';";
        sql_image_query.prepare(sql_display_image_query);

        if(sql_image_query.exec())
        {
            model.setQuery(sql_image_query);
            index = model.index(0,0);
            bytes = index.data().toByteArray();
            account_image.loadFromData(bytes);
            account_image.scaled(100, 100, Qt::KeepAspectRatio);
            sql_image_query.finish();
        }
        image->setData(Qt::DecorationRole, QPixmap::fromImage(account_image).scaledToHeight(100));

        ui->tableWidget->setItem(rowCount, 0, userID);
        ui->tableWidget->setItem(rowCount, 1, image);
        ui->tableWidget->setItem(rowCount, 2, username);
        ui->tableWidget->setItem(rowCount, 3, userType);
        rowCount++;
    }
    sql_select_mods_query.finish();
    database.close();
}

void AdminManageMods::on_tableWidget_cellClicked(int row, int column)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    ui->label->setText(
                "User ID: " + ui->tableWidget->item(row,0)->text() + "<br>" +
                "Username: " + ui->tableWidget->item(row,2)->text() + "<br>" +
                "User Type: " + ui->tableWidget->item(row,3)->text() + "<br>");

    selected_mod = ui->tableWidget->item(row,2)->text();
    ui->promote_button->setEnabled(true);
    ui->demote_button->setEnabled(true);
}

void AdminManageMods::on_promote_button_clicked()
{
    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    if(!database.open()){
        QMessageBox::warning(this,"Error","Database is not connected");
        return;
    }

    // Promoting users to mods
    QSqlQuery sql_update_query(QSqlDatabase::database(DB_NAME));
    QString sql_promote_mod_query = "UPDATE ";
    sql_promote_mod_query += TB_USERS;
    sql_promote_mod_query += " SET account_type = 'Mod' ";
    sql_promote_mod_query += " WHERE username = '" + selected_mod + "'";

    sql_update_query.prepare(sql_promote_mod_query);
    if(sql_update_query.exec(sql_promote_mod_query)){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        readDBandDisplayTable();
    }
    else{
        QMessageBox::warning(this,"Error","Failed to promote " + selected_mod);
        return;
    }
    sql_update_query.finish();
    database.close();
}

void AdminManageMods::on_demote_button_clicked()
{
    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    if(!database.open()){
        QMessageBox::warning(this,"Error","Database is not connected");
        return;
    }

    QSqlQuery sql_update_query(database);
    QString sql_demote_mod_query = "UPDATE ";
    sql_demote_mod_query += TB_USERS;
    sql_demote_mod_query += " SET account_type = 'User' ";
    sql_demote_mod_query += " WHERE username = '" + selected_mod + "'";

    sql_update_query.prepare(sql_demote_mod_query);
    if(sql_update_query.exec(sql_demote_mod_query)){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        readDBandDisplayTable();
    }
    else{
        QMessageBox::warning(this,"Error","Failed to demote " + selected_mod);
        return;
    }
    sql_update_query.finish();
    database.close();
}

void AdminManageMods::on_home_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminHome *admin_home;
    admin_home = new AdminHome(this);
    admin_home->show();
}

void AdminManageMods::on_manage_users_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageUsers *admin_m_users;
    admin_m_users = new  AdminManageUsers(this);
    admin_m_users->show();
}

void AdminManageMods::on_manage_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();
}

void AdminManageMods::on_manage_mods_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageMods *admin_m_mods;
    admin_m_mods = new  AdminManageMods(this);
    admin_m_mods->show();
}

void AdminManageMods::on_main_menu_button_clicked()
{
    inactivity_timer->stop();
    hide();
    HomePageNewest *home_page;
    home_page = new HomePageNewest(this);
    home_page->show();
}

void AdminManageMods::on_shutdown_button_clicked()
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

void AdminManageMods::on_logoff_button_clicked()
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

void AdminManageMods::set_accessibility_settings()
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
        ui->main_menu_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
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
