#include "adminmanagegroups.h"
#include "ui_adminmanagegroups.h"
#include "adminhome.h"
#include "adminmanageusers.h"
#include "adminmanagemods.h"
#include "global_variables.hpp"
#include "project_database.h"
#include "homepage.h"
#include "mainwindow.h"

#include <QMessageBox>

QString selected_group;
QString selected_group_user;
QTimer *account_type;

AdminManageGroups::AdminManageGroups(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminManageGroups)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->delete_button->setEnabled(false);
    ui->remove_button->setEnabled(false);
    ui->promote_button->setEnabled(false);
    ui->demote_button->setEnabled(false);
    ui->promote_button->hide();
    ui->demote_button->hide();
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));

    ui->logoff_button->setIcon(QIcon("logoff.png"));
    ui->logoff_button->setIconSize(QSize(45, 50));

    ui->account_name->setText(current_user);
    ui->profile_pic->setPixmap(QPixmap::fromImage(image).scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation));

    if(current_user != "username")
    {
        QTimer *update;
        update = new QTimer();
        QObject::connect(update, SIGNAL(timeout()),this, SLOT(update_date_time()));
        update->start(100);

        account_type = new QTimer();
        QObject::connect(account_type, SIGNAL(timeout()),this, SLOT(check_account_type()));
        account_type->start(1000);

        inactivity_timer = new QTimer();
        QObject::connect(inactivity_timer, SIGNAL(timeout()),this, SLOT(update_inactivity_status()));
        inactivity_timer->start(1000);
    }

    inactive_seconds = 0;
    inactive_minutes = 0;

    load_one_group();
    readDBandDisplayTable();
    set_accessibility_settings();

}

void AdminManageGroups::update_inactivity_status()
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

void AdminManageGroups::keyPressEvent(QKeyEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void AdminManageGroups::mousePressEvent(QMouseEvent *event) {
    inactive_seconds = 0;
    inactive_minutes = 0;
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void AdminManageGroups::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

AdminManageGroups::~AdminManageGroups()
{
    delete ui;
}

void AdminManageGroups::update_date_time()
{
    ui->currentDateTime->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void AdminManageGroups::check_account_type(){
    if (current_account_type == "Admin"){
        account_checked = true;
        ui->main_menu_button->hide();

    }
    else if(current_account_type == "Mod") {
        account_checked = true;
        ui->main_menu_button->show();

    }
    if(account_checked == true)
    {
        account_type->stop();
    }
}

void AdminManageGroups::load_one_group()
{
    if(group_manager == true)
    {
        ui->home_button->hide();
        ui->manage_mods_button->hide();
        ui->manage_users_button->hide();
        ui->manage_groups_button->hide();
        ui->main_menu_button->show();
        ui->promote_button->show();
        ui->demote_button->show();
    }
}

void AdminManageGroups::display_one_group()
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

    QSqlQuery sql_select_query(database);
    QString sql_select_users_query = "SELECT chat_users.user_id, chat_users.username, groupchat_users.group_id, group_chats.groupchat_name, groupchat_users.user_type FROM ";
    sql_select_users_query += TB_GROUPMEMBERS;
    sql_select_users_query += " INNER JOIN ";
    sql_select_users_query += TB_USERS;
    sql_select_users_query += " ON chat_users.user_id = groupchat_users.user_id ";
    sql_select_users_query += "INNER JOIN ";
    sql_select_users_query += TB_GROUPCHATS;
    sql_select_users_query += " ON groupchat_users.group_id = group_chats.groupchat_id ";
    sql_select_users_query += "WHERE group_chats.groupchat_name = :recipient AND groupchat_users.user_type NOT LIKE 'Admin' AND chat_users.username NOT LIKE :current_user ";
    sql_select_users_query += "ORDER BY group_id;";

    sql_select_query.prepare(sql_select_users_query);

    sql_select_query.bindValue(":recipient", current_recipient);
    sql_select_query.bindValue(":current_user", current_user);

    sql_select_query.exec();

    ui->tableWidget->setColumnCount(6);
    QStringList labels;
    labels << "Group ID" << "Group name" << "User ID" << "Profile Picture" << "Group Members"  << "User Type";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    int rowCount = 0;
    while(sql_select_query.next()){
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *groupID = new QTableWidgetItem;
        QTableWidgetItem *groupName = new QTableWidgetItem;
        QTableWidgetItem *userID = new QTableWidgetItem;
        QTableWidgetItem *image = new QTableWidgetItem;
        QTableWidgetItem *username = new QTableWidgetItem;
        QTableWidgetItem *userType = new QTableWidgetItem;

        userID->setText(sql_select_query.value(0).toString());
        username->setText(sql_select_query.value(1).toString());
        groupID->setText(sql_select_query.value(2).toString());
        groupName->setText(sql_select_query.value(3).toString());
        userType->setText(sql_select_query.value(4).toString());

        QModelIndex index;
        QSqlQueryModel model;
        QByteArray bytes;
        QSqlQuery image_query(database);

        QString user = sql_select_query.value(1).toString();
        QString str = "SELECT image FROM chat_users";
        str += " WHERE username = '" + user + "';";
        image_query.prepare(str);

        if(image_query.exec())
        {
            model.setQuery(image_query);
            index = model.index(0,0);
            bytes = index.data().toByteArray();
            account_image.loadFromData(bytes);
            account_image.scaled(100, 100, Qt::KeepAspectRatio);
            image_query.finish();
        }
        image->setData(Qt::DecorationRole, QPixmap::fromImage(account_image).scaledToHeight(100));

        ui->tableWidget->setItem(rowCount, 0, groupID);
        ui->tableWidget->setItem(rowCount, 1, groupName);
        ui->tableWidget->setItem(rowCount, 2, userID);
        ui->tableWidget->setItem(rowCount, 3, image);
        ui->tableWidget->setItem(rowCount, 4, username);
        ui->tableWidget->setItem(rowCount, 5, userType);
        rowCount++;
    }
    sql_select_query.finish();
    database.close();
}

void AdminManageGroups::display_all_groups()
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

    QSqlQuery sql_select_query(database);
    QString sql_select_users_query = "SELECT chat_users.user_id, chat_users.username, groupchat_users.group_id, group_chats.groupchat_name, groupchat_users.user_type FROM ";
    sql_select_users_query += TB_GROUPMEMBERS;
    sql_select_users_query += " INNER JOIN ";
    sql_select_users_query += TB_USERS;
    sql_select_users_query += " ON chat_users.user_id = groupchat_users.user_id ";
    sql_select_users_query += "INNER JOIN ";
    sql_select_users_query += TB_GROUPCHATS;
    sql_select_users_query += " ON groupchat_users.group_id = group_chats.groupchat_id ";
    sql_select_users_query += "WHERE  groupchat_users.user_type NOT LIKE 'Admin' ";
    sql_select_users_query += "ORDER BY group_id;";
    sql_select_query.prepare(sql_select_users_query);

    if(!sql_select_query.exec(sql_select_users_query)){
        QMessageBox::warning(this,"Error","Failed to display groups");
        return;
    }

    ui->tableWidget->setColumnCount(6);
    QStringList labels;
    labels << "Group ID" << "Group name" << "User ID" << "Profile Picture" << "Group Members"  << "User Type";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    int rowCount = 0;
    while(sql_select_query.next()){
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *groupID = new QTableWidgetItem;
        QTableWidgetItem *groupName = new QTableWidgetItem;
        QTableWidgetItem *userID = new QTableWidgetItem;
        QTableWidgetItem *image = new QTableWidgetItem;
        QTableWidgetItem *username = new QTableWidgetItem;
        QTableWidgetItem *userType = new QTableWidgetItem;

        userID->setText(sql_select_query.value(0).toString());
        username->setText(sql_select_query.value(1).toString());
        groupID->setText(sql_select_query.value(2).toString());
        groupName->setText(sql_select_query.value(3).toString());
        userType->setText(sql_select_query.value(4).toString());

        QModelIndex index;
        QSqlQueryModel model;
        QByteArray bytes;
        QSqlQuery image_query(database);

        QString user = sql_select_query.value(1).toString();
        QString str = "SELECT image FROM chat_users";
        str += " WHERE username = '" + user + "';";
        image_query.prepare(str);

        if(image_query.exec())
        {
            model.setQuery(image_query);
            index = model.index(0,0);
            bytes = index.data().toByteArray();
            account_image.loadFromData(bytes);
            account_image.scaled(100, 100, Qt::KeepAspectRatio);
            image_query.finish();
        }
        image->setData(Qt::DecorationRole, QPixmap::fromImage(account_image).scaledToHeight(100));

        ui->tableWidget->setItem(rowCount, 0, groupID);
        ui->tableWidget->setItem(rowCount, 1, groupName);
        ui->tableWidget->setItem(rowCount, 2, userID);
        ui->tableWidget->setItem(rowCount, 3, image);
        ui->tableWidget->setItem(rowCount, 4, username);
        ui->tableWidget->setItem(rowCount, 5, userType);
        rowCount++;
    }
    sql_select_query.finish();
    database.close();
}

void AdminManageGroups::readDBandDisplayTable()
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    if(group_manager == false)
    {
        display_all_groups();
    }
    else
    {
        display_one_group();
    }
}

void AdminManageGroups::on_tableWidget_cellClicked(int row, int column)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    ui->label->setText(
                "Group ID: " + ui->tableWidget->item(row,0)->text() + "<br>" +
                "Group Name: " + ui->tableWidget->item(row,1)->text() + "<br>" +
                "User ID: " + ui->tableWidget->item(row,2)->text() + "<br>" +
                "Username: " + ui->tableWidget->item(row,4)->text() + "<br>" +
                "User Type: " + ui->tableWidget->item(row,5)->text() + "<br>");

    selected_group = ui->tableWidget->item(row,0)->text();
    selected_group_user = ui->tableWidget->item(row,2)->text();

    if(ui->tableWidget->item(row, 5)->text() == "Mod")
    {
        ui->demote_button->setEnabled(true);
        ui->promote_button->setEnabled(false);
    }
    else
    {
        ui->promote_button->setEnabled(true);
        ui->demote_button->setEnabled(false);
    }
    ui->delete_button->setEnabled(true);
    ui->remove_button->setEnabled(true);
}

void AdminManageGroups::on_delete_button_clicked()
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

    // Deleting group from table group_chats
    QSqlQuery sql_delete_query(database);
    QString sql_remove_member_query = "DELETE FROM ";
    sql_remove_member_query += TB_GROUPCHATS;
    sql_remove_member_query += " WHERE groupchat_id = " + selected_group;
    sql_delete_query.prepare(sql_remove_member_query);

    // Deleting group from table groupchat_users
    QSqlQuery sql_delete_query_2(database);
    QString sql_delete_group_query = "DELETE FROM ";
    sql_delete_group_query += TB_GROUPMEMBERS;
    sql_delete_group_query += " WHERE group_id = " + selected_group;
    sql_delete_query_2.prepare(sql_delete_group_query);

    if((sql_delete_query.exec(sql_remove_member_query)) && (sql_delete_query_2.exec(sql_delete_group_query))){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        readDBandDisplayTable();
    }
    else{
        QMessageBox::warning(this,"Error","Failed to delete group" + selected_group);
        return;
    }
    sql_delete_query.finish();
    sql_delete_query_2.finish();
    database.close();
}

void AdminManageGroups::on_remove_button_clicked()
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

    QSqlQuery sql_delete_query(QSqlDatabase::database(DB_NAME));
    QString sql_remove_user_query = "DELETE FROM ";
    sql_remove_user_query += TB_GROUPMEMBERS;
    sql_remove_user_query += " WHERE user_id = " + selected_group_user;
    sql_remove_user_query += " AND group_id = " + selected_group;

    sql_delete_query.prepare(sql_remove_user_query);
    if(sql_delete_query.exec(sql_remove_user_query)){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        readDBandDisplayTable();
    }
    else{
        QMessageBox::warning(this,"Error","Failed to remove " + selected_group_user + " from " + selected_group);
        return;
    }
    sql_delete_query.finish();
    database.close();
}

void AdminManageGroups::on_home_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminHome *admin_home;
    admin_home = new AdminHome(this);
    admin_home->show();
}

void AdminManageGroups::on_manage_users_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageUsers *admin_m_users;
    admin_m_users = new  AdminManageUsers(this);
    admin_m_users->show();
}

void AdminManageGroups::on_manage_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();
}

void AdminManageGroups::on_manage_mods_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageMods *admin_m_mods;
    admin_m_mods = new  AdminManageMods(this);
    admin_m_mods->show();
}

void AdminManageGroups::on_main_menu_button_clicked()
{
    inactivity_timer->stop();
    group_manager = false;

    hide();
    HomePageNewest *home_page;
    home_page = new HomePageNewest(this);
    home_page->show();
}

void AdminManageGroups::on_shutdown_button_clicked()
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

void AdminManageGroups::on_logoff_button_clicked()
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


void AdminManageGroups::on_promote_button_clicked()
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
    sql_promote_mod_query += TB_GROUPMEMBERS;
    sql_promote_mod_query += " INNER JOIN ";
    sql_promote_mod_query += TB_GROUPCHATS;
    sql_promote_mod_query += " ON ";
    sql_promote_mod_query += TB_GROUPCHATS;
    sql_promote_mod_query += ".groupchat_id = ";
    sql_promote_mod_query += TB_GROUPMEMBERS;
    sql_promote_mod_query += ".group_id ";
    sql_promote_mod_query += "INNER JOIN ";
    sql_promote_mod_query += TB_USERS;
    sql_promote_mod_query += " ON ";
    sql_promote_mod_query += TB_USERS;
    sql_promote_mod_query += ".user_id = ";
    sql_promote_mod_query += TB_GROUPMEMBERS;
    sql_promote_mod_query += ".user_id ";
    sql_promote_mod_query += " SET user_type = 'Mod' ";
    sql_promote_mod_query += " WHERE chat_users.user_id = '" + selected_group_user + "' AND group_chats.groupchat_name = '" + current_recipient + "'";

    sql_update_query.prepare(sql_promote_mod_query);
    if(sql_update_query.exec(sql_promote_mod_query)){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        readDBandDisplayTable();
    }
    else{
        QMessageBox::warning(this,"Error","Failed to promote " + selected_group_user);
        return;
    }
    sql_update_query.finish();
    database.close();
}

void AdminManageGroups::on_demote_button_clicked()
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
    QString sql_demote_mod_query = "UPDATE ";
    sql_demote_mod_query += TB_GROUPMEMBERS;
    sql_demote_mod_query += " INNER JOIN ";
    sql_demote_mod_query += TB_GROUPCHATS;
    sql_demote_mod_query += " ON ";
    sql_demote_mod_query += TB_GROUPCHATS;
    sql_demote_mod_query += ".groupchat_id = ";
    sql_demote_mod_query += TB_GROUPMEMBERS;
    sql_demote_mod_query += ".group_id ";
    sql_demote_mod_query += "INNER JOIN ";
    sql_demote_mod_query += TB_USERS;
    sql_demote_mod_query += " ON ";
    sql_demote_mod_query += TB_USERS;
    sql_demote_mod_query += ".user_id = ";
    sql_demote_mod_query += TB_GROUPMEMBERS;
    sql_demote_mod_query += ".user_id ";
    sql_demote_mod_query += " SET user_type = 'User' ";
    sql_demote_mod_query += " WHERE chat_users.user_id = '" + selected_group_user + "' AND group_chats.groupchat_name = '" + current_recipient + "'";

    sql_update_query.prepare(sql_demote_mod_query);
    if(sql_update_query.exec(sql_demote_mod_query)){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        readDBandDisplayTable();
    }
    else{
        QMessageBox::warning(this,"Error","Failed to promote " + selected_group_user);
        return;
    }
    sql_update_query.finish();
    database.close();
}

void AdminManageGroups::set_accessibility_settings()
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
        ui->page_title_label->setStyleSheet("#page_title_label {color: DimGrey;	font-size: 50px;} ");
        ui->sidebar->setStyleSheet("#sidebar { background-color: LightGrey; border-radius: 8px; } "
                                   "QLabel { color: white; } "
                                   "QPushButton { color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px; } "
                                   "QPushButton:hover { background-color: DarkOrange; color: white; }");
        ui->page_contents_widget->setStyleSheet("");
    }
}
