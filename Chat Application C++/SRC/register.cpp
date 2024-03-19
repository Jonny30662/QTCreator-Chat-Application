#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include "global_variables.hpp"
#include "project_database.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <regex>
#include <QScreen>



using namespace std;
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));

    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);


    QTimer *update;
    update = new QTimer();
    QObject::connect(update, SIGNAL(timeout()),this, SLOT(update_date_time()));
    update->start(100);
}

void Register::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Register::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void Register::update_date_time()
{
    ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

Register::~Register()
{
    delete ui;
}

void Register::on_back_to_login_clicked()
{
    hide();
    MainWindow *main_window;
    main_window = new MainWindow(this);
    main_window->show();
}

void Register::on_register_button_clicked()
{
    QString username = ui->username_input->text();
    QString password = ui->password_input->text();
    QString confirm_password = ui->confirm_password_input->text();
    QString first_name = ui->first_name_input->text();
    QString last_name = ui->last_name_input->text();
    QString email = ui->email_input->text();
    QString special_word = ui->special_word_input->text();
    QRegularExpression regex("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    static QString active_status = "Offline";
    static QString account_type = "User";
    static QString accessibility_preference = "Light";

    bool password_has_number = false;
    bool password_has_Scharacter = false;
    bool has_space = false;
    for (int i =0;i<password.size();i++){
        if (password[i].isDigit()){
            password_has_number = true;
        }
        if ((password[i] == "!") || (password[i] == "$") || (password[i] == "%") || (password[i] == "&") || (password[i] == "*") || (password[i] == "?") || (password[i] == "#")){
            password_has_Scharacter = true;
        }
    }
    for (int i =0;i<special_word.size();i++){
        if (special_word[i] == " "){
            has_space = true;
        }
    }

    if ((!username.isEmpty()) && (!password.isEmpty()) && (!confirm_password.isEmpty()) && (!first_name.isEmpty()) && (!last_name.isEmpty()) && (!email.isEmpty() && (!special_word.isEmpty())) ){
        if (has_space == false){
            if (password == confirm_password){
                if ((password.length() >= 8) && (password_has_number == true) && (password_has_Scharacter == true)){
                    if(regex.match(email).hasMatch()){
                        QString password_coded = Encrypt(password, 4);
                        if(database.open()){
                            QByteArray arr;
                            QFile *file = new QFile("default_user.jpg");
                            file->open(QIODevice::ReadOnly);
                            arr = file->readAll();
                            QBuffer buffer(&arr);
                            buffer.open(QIODevice::WriteOnly);

                            QSqlQuery qry;
                            QString sql_sentence = "INSERT INTO ";
                            sql_sentence += TB_USERS;
                            sql_sentence += " (username,first_name,last_name,password,email,special_word,active_status, account_type, image, accessibility_preference)";
                            sql_sentence += " VALUES (:username,:first_name,:last_name,:password,:email,:special_word,:active_status, :account_type, :image, :accessibility_preference)";
                            qry.prepare(sql_sentence);

                            qry.bindValue(":username", username);
                            qry.bindValue(":first_name", first_name);
                            qry.bindValue(":last_name", last_name);
                            qry.bindValue(":password", password_coded);
                            qry.bindValue(":email", email);
                            qry.bindValue(":special_word", special_word);
                            qry.bindValue(":active_status", active_status);
                            qry.bindValue(":account_type", account_type);
                            qry.bindValue(":image", arr, QSql::InOut | QSql::Binary);
                            qry.bindValue(":accessibility_preference", accessibility_preference);

                            if(qry.exec())
                            {
                                hide();
                                MainWindow *main_window;
                                main_window = new MainWindow(this);
                                main_window->show();
                            }
                            else
                            {
                                QMessageBox::warning(this, "Error", "Username already exists");
                            }
                        }
                        else
                        {
                            QMessageBox::warning(this,"Error","Database is not connected");
                        }
                    }
                    else
                    {
                        QMessageBox::warning(this,"Error","Invalid email address");
                    }
                }
                else
                {
                    QMessageBox::warning(this,"Error","password must have 8 characters or more and must contain  at least 1 number and 1 special character '!$%&*?#' ");
                }
            }
            else
            {
                QMessageBox::warning(this,"Error","Password doesn't match confirm password");
            }
        }
        else
        {
            QMessageBox::warning(this,"Error","Special word must be one word");
        }
    }
    else
    {
        QMessageBox::warning(this,"Error","You must fill in all the details");
    }
    database.close();
}

QString Register::Encrypt(QString password_unencrypted, int key)
{
    std::string result = "";
    std::string password_unencrypted_string = password_unencrypted.toStdString();

    for (int i = 0; i < password_unencrypted_string.length(); i++)
    {
        if (password_unencrypted_string[i] == ' '){
            result += ' ';
        }
        else if((password_unencrypted_string[i] == '0') || (password_unencrypted_string[i] == '1') || (password_unencrypted_string[i] == '2') || (password_unencrypted_string[i] == '3') || (password_unencrypted_string[i] == '4') || (password_unencrypted_string[i] == '5') || (password_unencrypted_string[i] == '6') || (password_unencrypted_string[i] == '7') || (password_unencrypted_string[i] == '8') || (password_unencrypted_string[i] == '9'))   {
            result += password_unencrypted_string[i];
        }
        else if((password_unencrypted_string[i] == '!') || (password_unencrypted_string[i] == '$') || (password_unencrypted_string[i] == '%') || (password_unencrypted_string[i] == '&') || (password_unencrypted_string[i] == '*') || (password_unencrypted_string[i] == '?')){
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

void Register::on_shutdown_button_clicked()
{
    QCoreApplication::exit();
}
