#include "homepage.h"
#include "settings.h"
#include "groups.h"
#include "accounts.h"
#include "ui_homepage.h"
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

HomePageNewest::HomePageNewest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePageNewest)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));

    ui->logoff_button->setIcon(QIcon("logoff.png"));
    ui->logoff_button->setIconSize(QSize(45, 50));

    ui->account_name->setText(current_user);
    ui->profile_pic->setPixmap(QPixmap::fromImage(image).scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation));

    check_account_type();
    set_accessibility_settings();

    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

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

HomePageNewest::~HomePageNewest()
{
    delete ui;
}

void HomePageNewest::update_inactivity_status()
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

void HomePageNewest::keyPressEvent(QKeyEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void HomePageNewest::mousePressEvent(QMouseEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void HomePageNewest::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate); 
}

void HomePageNewest::update_date_time()
{
     ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void HomePageNewest::check_account_type()
{
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

void HomePageNewest::on_home_button_clicked()
{
    inactivity_timer->stop();
    hide();
    HomePageNewest *home_page_newest;
    home_page_newest = new HomePageNewest(this);
    home_page_newest->show();
}

void HomePageNewest::on_chats_button_clicked()
{
    inactivity_timer->stop();
    hide();
    ExistingChats *existing_chats;
    existing_chats = new ExistingChats(this);
    existing_chats->show();
}

void HomePageNewest::on_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Groups *groups;
    groups = new Groups(this);
    groups->show();
}

void HomePageNewest::on_accounts_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Accounts *accounts;
    accounts = new Accounts(this);
    accounts->show();
}

void HomePageNewest::on_settings_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Settings *settings;
    settings = new Settings(this);
    settings->show();
}

void HomePageNewest::on_manage_users_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageUsers *admin_m_users;
    admin_m_users = new  AdminManageUsers(this);
    admin_m_users->show();
}

void HomePageNewest::on_manage_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();
}

void HomePageNewest::on_manage_mods_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageMods *admin_m_mods;
    admin_m_mods = new  AdminManageMods(this);
    admin_m_mods->show();
}

void HomePageNewest::on_logoff_button_clicked()
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

void HomePageNewest::on_shutdown_button_clicked()
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

void HomePageNewest::set_accessibility_settings()
{
    if(dark_mode_toggle == "Dark"){
        QString white_colour = "white";
        QString grey_colour = "Grey";
        QString dim_grey_colour = "DimGrey";
        QString light_grey_colour = "lightGrey";

        ui->central_widget->setStyleSheet("#central_widget { background-color: " + grey_colour + ";}");
        ui->page_name_widget->setStyleSheet("#page_name_widget { background-color: " + grey_colour + ";border-radius: 8px;}");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: " + white_colour + ";\n	font-size: 50px;\n}");
        ui->page_information->setStyleSheet("#page_information {background-color: " + grey_colour + "; color: " + white_colour + "}");
        ui->sidebar->setStyleSheet("#sidebar { background-color: "+ grey_colour + ";border-radius: 8px;} "
                                   "QLabel { color: " + white_colour + ";} "
                                   "QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_groups_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_mods_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_users_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget { background-color: " + grey_colour + "; border-radius: 8px;}");
    }

    else if (dark_mode_toggle == "Light"){
        ui->central_widget->setStyleSheet("");
        ui->page_name_widget->setStyleSheet("#page_name_widget{ \n background-color: white;\n border-radius: 8px;\n}");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: DimGrey;\n	font-size: 50px;\n}");
        ui->sidebar->setStyleSheet("#sidebar { background-color: LightGrey;border-radius: 8px;} "
                                   "QLabel { color: white; } "
                                   "QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget { \n background-color: white;\n border-radius: 8px;\n}");
    }
}
