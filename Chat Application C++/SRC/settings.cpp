#include "homepage.h"
#include "settings.h"
#include "groups.h"
#include "accounts.h"
#include "ui_settings.h"
#include "QTimer"
#include "QDateTime"
#include "global_variables.hpp"
#include <QMessageBox>
#include "project_database.h"
#include "existingchats.h"
#include "existingchats.h"
#include "adminmanageusers.h"
#include "adminmanagegroups.h"
#include "adminmanagemods.h"
#include "global_variables.hpp"
#include "mainwindow.h"
#include <QFileDialog>
#include <QDir>

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
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

Settings::~Settings()
{
    delete ui;
}

void Settings::update_inactivity_status()
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

void Settings::keyPressEvent(QKeyEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void Settings::mousePressEvent(QMouseEvent *event) {
    inactive_seconds = 0;
    inactive_minutes = 0;
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Settings::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void Settings::update_date_time()
{
    ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void Settings::check_account_type(){
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

void Settings::update_username()
{
    if(!database.open()){
        QMessageBox::warning(this,"Error","Database is not connected");
        return;
    }

    QString username = ui->new_username->text();
    QSqlQuery sql_update_query(database);
    QString sql_username_query = "UPDATE ";
    sql_username_query += TB_USERS;
    sql_username_query += " SET username = '" + username + "'";
    sql_username_query += " WHERE username = '" + current_user + "'";

    if(!sql_update_query.exec(sql_username_query)){
        QMessageBox::warning(this,"Error","Your username has not been updated");
    }
    else{
        QMessageBox::information(this,"Success","Your username has been updated");
        current_user = username;
        ui->account_name->setText(current_user);
    }
    sql_update_query.finish();
    database.close();
}

void Settings::update_password()
{
    if(database.open())
    {
        QString password = ui->new_password->text();
        bool password_has_number_ = false;
        bool password_has_Scharacter_ = false;

        for (int i =0;i < password.size();i++){
            if (password[i].isDigit()){
                password_has_number_ = true;
            }
            if ((password[i] == "!") ||
                    (password[i] == "$") ||
                    (password[i] == "%") ||
                    (password[i] == "&") ||
                    (password[i] == "*") ||
                    (password[i] == "?") ||
                    (password[i] == "#")){
                password_has_Scharacter_ = true;
            }
        }
        if (password.length() >= 8)
        {
            if(password_has_number_ == true)
            {
                if (password_has_Scharacter_ == true)
                {
                    QString password_coded = Encrypt(password, 4);

                    QSqlQuery sql_update_query(database);
                    QString sql_update_password_query = "UPDATE ";
                    sql_update_password_query += TB_USERS;
                    sql_update_password_query += " SET password = '"+ password_coded + "'";
                    sql_update_password_query += " WHERE username = '" + current_user + "'";

                    if(!sql_update_query.exec(sql_update_password_query)){
                        image = image.scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation);
                        ui->profile_pic->setPixmap(QPixmap::fromImage(image));
                    }
                    else
                    {
                        QMessageBox::information(this,"Success","Your password has been updated");
                    }
                    sql_update_query.finish();
                }
                else
                {
                    QMessageBox::warning(this,"Error","password must contain at least 1 special character '!$%&*?#' ");
                }
            }
            else
            {
                QMessageBox::warning(this,"Error","password must contain at least 1 number");
            }
        }
        else
        {
            QMessageBox::warning(this,"Error","password must have 8 characters or more");
        }
    }
    database.close();
}

void Settings::update_first_name()
{
    if(database.open())
    {
        QString first_name= ui->new_first_name->text();
        QSqlQuery sql_update_query(database);
        QString sql_update_first_name_query = "UPDATE ";
        sql_update_first_name_query += TB_USERS;
        sql_update_first_name_query += " SET first_name = '"+ first_name + "'";
        sql_update_first_name_query += " WHERE username = '" + current_user + "'";

        if(!sql_update_query.exec(sql_update_first_name_query)){
            QMessageBox::warning(this,"Error","Your first name has not been updated");
        }
        else{
            QMessageBox::information(this,"Success","Your first name has been updated");
        }
        sql_update_query.finish();
    }
    database.close();
}

void Settings::update_last_name()
{
    if(database.open())
    {
        QString last_name = ui->new_last_name->text();
        QSqlQuery sql_update_query(database);
        QString sql_update_last_name_query = "UPDATE ";
        sql_update_last_name_query += TB_USERS;
        sql_update_last_name_query += " SET last_name = '"+ last_name + "'";
        sql_update_last_name_query += " WHERE username = '" + current_user + "'";

        if(!sql_update_query.exec(sql_update_last_name_query)){
            QMessageBox::warning(this,"Error","Your last name has not been updated");
            return;
        }
        else
        {
            QMessageBox::information(this,"Success","Your last name has been updated");
        }

        sql_update_query.finish();
    }
    database.close();
}

void Settings::update_email()
{
    if(database.open())
    {
        QString email = ui->new_email->text();
        QSqlQuery sql_update_query(database);
        QString sql_update_email_query = "UPDATE ";
        sql_update_email_query += TB_USERS;
        sql_update_email_query += " SET email = '"+ email + "'";
        sql_update_email_query += " WHERE username = '" + current_user + "'";

        if(!sql_update_query.exec(sql_update_email_query)){
            QMessageBox::warning(this,"Error","Your email has not been updated");
            return;
        }
        else{
            QMessageBox::information(this,"Success","Your email has been updated");
        }
        sql_update_query.finish();
    }
    database.close();
}

void Settings::update_special_word()
{
    if(database.open()){
        QString special_word = ui->new_special_word->text();
        bool has_space = false;

        for (int i =0;i<special_word.size();i++){
            if (special_word[i] == " "){
                has_space = true;
            }
        }
        if (has_space == false){
            QSqlQuery sql_update_query(database);
            QString sql_update_special_word_query = "UPDATE ";
            sql_update_special_word_query += TB_USERS;
            sql_update_special_word_query += " SET special_word = '" + special_word + "'";
            sql_update_special_word_query += " WHERE username = '" + current_user + "'";

            if(!sql_update_query.exec(sql_update_special_word_query)){
                QMessageBox::warning(this,"Error","Your special word has not been updated");
                return;
            }
            else{
                QMessageBox::information(this,"Success","Your special word has been updated");
            }
            sql_update_query.finish();
        }else
        {
            QMessageBox::warning(this,"Error", "Special Word Cannot have a space in it" );
        }
    }

}

QString Settings::Encrypt(QString password_unencrypted, int key)
{
    std::string result = "";
    std::string password_unencrypted_string = password_unencrypted.toStdString();

    for (int i = 0; i < password_unencrypted_string.length(); i++)
    {
        if (password_unencrypted_string[i] == ' '){
            result += ' ';
        }
        else if((password_unencrypted_string[i] == '0') ||
                (password_unencrypted_string[i] == '1') ||
                (password_unencrypted_string[i] == '2') ||
                (password_unencrypted_string[i] == '3') ||
                (password_unencrypted_string[i] == '4') ||
                (password_unencrypted_string[i] == '5') ||
                (password_unencrypted_string[i] == '6') ||
                (password_unencrypted_string[i] == '7') ||
                (password_unencrypted_string[i] == '8') ||
                (password_unencrypted_string[i] == '9')){
            result += password_unencrypted_string[i];
        }
        else if((password_unencrypted_string[i] == '!') ||
                (password_unencrypted_string[i] == '$') ||
                (password_unencrypted_string[i] == '%') ||
                (password_unencrypted_string[i] == '&') ||
                (password_unencrypted_string[i] == '*') ||
                (password_unencrypted_string[i] == '?')){
            result += password_unencrypted_string[i];
        }

        else if (std::isalpha(password_unencrypted_string[i])){
            if (std::isupper(password_unencrypted_string[i])){
                result += char(int(password_unencrypted_string[i]+key-65)%26 +65);
            }
            else{
                result += char(int(password_unencrypted_string[i]+key-97)%26 +97);
            }
        }

    }
    return QString::fromStdString(result);
}

void Settings::on_browse_button_clicked()
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    QString file_name = QFileDialog::getOpenFileName(this, tr("Choose a profile picture"), QDir::homePath(), tr("Image Files (*.jpg)"));
    if(QString::compare(file_name, QString()) != 0){
        bool valid = image.load(file_name);

        if(valid){
            if(database.open()){
                QSqlQuery sqlQueryImage(database);
                QByteArray arr;
                QBuffer buffer(&arr);
                buffer.open(QIODevice::WriteOnly);
                image.save(&buffer, "jpg");

                sqlQueryImage.prepare("UPDATE chat_users SET image = :image WHERE username = :username");
                sqlQueryImage.bindValue(":image", arr, QSql::InOut | QSql::Binary);
                sqlQueryImage.bindValue(":username", current_user, QSql::InOut | QSql::Binary);

                if (!sqlQueryImage.exec()) {
                    QMessageBox::warning(this,"Error", "Failed to update profile picture");
                    return;
                }
                else{
                    ui->profile_pic->setPixmap(QPixmap::fromImage(image).scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation));
                }
            }
        }
    }
}

void Settings::on_home_button_clicked()
{
    inactivity_timer->stop();
    hide();
    HomePageNewest *home_page_newest;
    home_page_newest = new HomePageNewest(this);
    home_page_newest->show();
}

void Settings::on_chats_button_clicked()
{
    inactivity_timer->stop();
    hide();
    ExistingChats *existing_chats;
    existing_chats = new ExistingChats(this);
    existing_chats->show();
}

void Settings::on_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Groups *groups;
    groups = new Groups(this);
    groups->show();
}

void Settings::on_accounts_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Accounts *accounts;
    accounts = new Accounts(this);
    accounts->show();
}

void Settings::on_settings_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Settings *settings;
    settings = new Settings(this);
    settings->show();
}

void Settings::on_manage_users_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageUsers *admin_m_users;
    admin_m_users = new  AdminManageUsers(this);
    admin_m_users->show();
}

void Settings::on_manage_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();
}

void Settings::on_manage_mods_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageMods *admin_m_mods;
    admin_m_mods = new  AdminManageMods(this);
    admin_m_mods->show();
}

void Settings::on_shutdown_button_clicked()
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

void Settings::on_update_details_button_clicked()
{
    inactive_seconds = 0;
    inactive_minutes = 0;
    QString username = ui->new_username->text();
    QString password = ui->new_password->text();
    QString first_name = ui->new_first_name->text();
    QString last_name = ui->new_last_name->text();
    QString email = ui->new_email->text();
    QString special_word = ui->new_special_word->text();

    // Code for updating the username
    if (!username.isEmpty())
    {
        update_username();
    }

    // Code for updating the password
    if (!password.isEmpty())
    {
        update_password();
    }

    // Code for updating the first name
    if (!first_name.isEmpty()){
        update_first_name();
    }

    // Code for updating the last name
    if (!last_name.isEmpty()){
        update_last_name();
    }

    // Code for updating the email
    if (!email.isEmpty()){
        update_email();
    }

    // Code for updating the special word
    if(!special_word.isEmpty()){
        update_special_word();
    }
}

void Settings::on_logoff_button_clicked()
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

void Settings::on_accessibility_button_clicked()
{
    if(dark_mode_toggle == "Light"){
        dark_mode_toggle = "Dark";
        QString white_colour = "white";
        QString grey_colour = "Grey";
        QString dim_grey_colour = "DimGrey";
        QString light_grey_colour = "lightGrey";

        ui->accessibility_button->setText("Light Mode");
        ui->accessibility_button->setStyleSheet("#accessibility_button { background-color: black; border-radius: 8px; color: white;}"
                                        " #accessibility_button:hover { background-color: white; color: black;}");
        ui->central_widget->setStyleSheet("#central_widget { background-color: " + grey_colour + ";}");
        ui->page_name_widget->setStyleSheet("#page_name_widget { background-color: " + light_grey_colour + "; border-radius: 8px;}");
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
        ui->page_contents_widget->setStyleSheet("#page_contents_widget {background-color: " + light_grey_colour + "; border-radius: 8px;}");
        ui->setting_left_widget->setStyleSheet("#setting_left_widget{background-color: " + light_grey_colour + ";border-radius: 8px;}"
                                               "QPushButton {color: DimGrey;background-color: White;border-width: 0px;border-radius: 2px;}"
                                               "QPushButton:hover { background-color: DarkOrange;color: white;}");
    }

    else{
        dark_mode_toggle = "Light";
        ui->accessibility_button->setText("Dark Mode");
        ui->accessibility_button->setStyleSheet("#accessibility_button { background-color: white; border-radius: 8px; color: black;}"
                                        "#accessibility_button:hover { background-color: black; color: white;}");
        ui->central_widget->setStyleSheet("");
        ui->page_name_widget->setStyleSheet("#page_name_widget { \n background-color: white;\n border-radius: 8px;\n}");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: DimGrey;\n	font-size: 50px;\n}");
        ui->sidebar->setStyleSheet("#sidebar { background-color: LightGrey;border-radius: 8px;} "
                                   "QLabel { color: white; } "
                                   "QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->manage_groups_button->setStyleSheet("QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->manage_mods_button->setStyleSheet("QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->manage_users_button->setStyleSheet("QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget {background-color: white; border-radius: 8px;}");
        ui->setting_left_widget->setStyleSheet("#setting_left_widget{ background-color: white;border-radius: 8px;}"
                                               "QPushButton {color: DimGrey;background-color: White;border-width: 0px;border-radius: 2px;}"
                                               "QPushButton:hover {background-color: DarkOrange;color: white;}");
    }

    if(database.open())
    {
        QSqlQuery sql_update_query;
        QString sql_sentence = "UPDATE ";
        sql_sentence += TB_USERS;
        if(dark_mode_toggle == "Light")
        {
            sql_sentence += " SET accessibility_preference = 'Light' ";
        }
        else
        {
            sql_sentence += " SET accessibility_preference = 'Dark' ";
        }

        sql_sentence += "WHERE username = '" +current_user + "';";

        sql_update_query.prepare(sql_sentence);

        sql_update_query.exec();

        sql_update_query.finish();
        database.close();
    }
}

void Settings::set_accessibility_settings()
{
    if(dark_mode_toggle == "Dark"){
        QString white_colour = "white";
        QString grey_colour = "Grey";
        QString dim_grey_colour = "DimGrey";
        QString light_grey_colour = "lightGrey";

        ui->accessibility_button->setText("Light Mode");
        ui->accessibility_button->setStyleSheet("#accessibility_button { background-color: black; border-radius: 8px; color: white;}"
                                        "#accessibility_button:hover { background-color: white; color: black;}");
        ui->central_widget->setStyleSheet("#central_widget { background-color: " + grey_colour + ";}");
        ui->page_name_widget->setStyleSheet("#page_name_widget { \n background-color: " + light_grey_colour + ";\n border-radius: 8px;\n}");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: " + white_colour + ";\n	font-size: 50px;\n}");
        ui->sidebar->setStyleSheet("#sidebar { background-color: "+ grey_colour + ";border-radius: 8px;} "
                                   "QLabel { color: " + white_colour + ";} "
                                   "QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;}"
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_groups_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_mods_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + "; }");
        ui->manage_users_button->setStyleSheet("QPushButton {color: " + white_colour + ";background-color: "+ dim_grey_colour + "; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: " + white_colour + ";}");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget { background-color: " + light_grey_colour + "; border-radius: 8px;}");
        ui->setting_left_widget->setStyleSheet("#setting_left_widget{background-color: " + light_grey_colour + ";border-radius: 8px;}"
                                               "QPushButton {color: DimGrey;background-color: White;border-width: 0px;border-radius: 2px;}"
                                               "QPushButton:hover { background-color: DarkOrange;color: white;}");
    }

    else{
        ui->accessibility_button->setText("Dark Mode");
        ui->accessibility_button->setStyleSheet("#accessibility_button { background-color: white; border-radius: 8px; color: black;}"
                                        "#accessibility_button:hover { background-color: black; color: white;}");
        ui->central_widget->setStyleSheet("");
        ui->page_name_widget->setStyleSheet("#page_name_widget { \n background-color: white;\n border-radius: 8px;\n}");
        ui->page_title_label->setStyleSheet("#page_title_label {\n	color: DimGrey;\n	font-size: 50px;\n}");
        ui->sidebar->setStyleSheet("#sidebar {background-color: LightGrey;border-radius: 8px;}"
                                   "QLabel {color: white;} "
                                   "QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;}"
                                   "QPushButton:hover {background-color: DarkOrange; color: white;}");
        ui->manage_groups_button->setStyleSheet("QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;} "
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->manage_mods_button->setStyleSheet("QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;}"
                                   "QPushButton:hover {background-color: DarkOrange; color: white; }");
        ui->manage_users_button->setStyleSheet("QPushButton {color: DimGrey;background-color: white; border-width: 0px; border-radius: 2px;}"
                                   "QPushButton:hover {background-color: DarkOrange; color: white;}");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget { \n background-color: white;\n border-radius: 8px;\n}");
        ui->setting_left_widget->setStyleSheet("#setting_left_widget{ background-color: white;border-radius: 8px;}"
                                               "QPushButton {color: DimGrey;background-color: White;border-width: 0px;border-radius: 2px;}"
                                               "QPushButton:hover {background-color: DarkOrange;color: white;}");
    }
}

void Settings::on_new_username_cursorPositionChanged(int arg1, int arg2)
{
    inactive_minutes = 0;
    inactive_seconds = 0;
}

void Settings::on_new_password_cursorPositionChanged(int arg1, int arg2)
{
    inactive_minutes = 0;
    inactive_seconds = 0;
}

void Settings::on_new_first_name_cursorPositionChanged(int arg1, int arg2)
{
    inactive_minutes = 0;
    inactive_seconds = 0;
}

void Settings::on_new_last_name_cursorPositionChanged(int arg1, int arg2)
{
    inactive_minutes = 0;
    inactive_seconds = 0;
}

void Settings::on_new_email_cursorPositionChanged(int arg1, int arg2)
{
    inactive_minutes = 0;
    inactive_seconds = 0;
}

void Settings::on_new_special_word_cursorPositionChanged(int arg1, int arg2)
{
    inactive_minutes = 0;
    inactive_seconds = 0;
}
