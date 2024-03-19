#include "forgottenpassword.h"
#include "ui_forgottenpassword.h"
#include "mainwindow.h"
#include "global_variables.hpp"
#include "project_database.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>
#include <QDebug>
#include <homepage.h>
#include <QDateTime>
#include <QTimer>


ForgottenPassword::ForgottenPassword(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForgottenPassword)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));

    QTimer *update;
    update = new QTimer();
    QObject::connect(update, SIGNAL(timeout()),this, SLOT(update_date_time()));
    update->start(100);
}

ForgottenPassword::~ForgottenPassword()
{
    delete ui;
}

void ForgottenPassword::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void ForgottenPassword::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void ForgottenPassword::update_date_time()
{
    ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void ForgottenPassword::on_shutdown_button_clicked()
{
   QCoreApplication::exit();
}

void ForgottenPassword::on_change_password_button_clicked()
{
    QString username_entered = ui->username->text();
    QString special_word_entered = ui->special_word->text();
    QString new_password = ui->new_password->text();
    QString confirm_new_password = ui->confirm_new_password->text();

    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    bool password_has_number = false;
    bool password_has_Scharacter = false;
    bool has_space = false;

    for (int i =0;i<new_password.size();i++){
        if (new_password[i].isDigit()){
            password_has_number = true;
        }
        if ((new_password[i] == "!") || (new_password[i] == "$") || (new_password[i] == "%") || (new_password[i] == "&") || (new_password[i] == "*") || (new_password[i] == "?") || (new_password[i] == "#")){
            password_has_Scharacter = true;
        }
    }

    if ((!username_entered.isEmpty()) && (!special_word_entered.isEmpty()) && (!new_password.isEmpty()) && (!confirm_new_password.isEmpty())){
        QString password_coded = Encrypt(new_password, 4);
        if (database.open()){
            QSqlQuery query(QSqlDatabase::database(DB_NAME));
            QString sql_update_query ="SELECT username, password, special_word FROM ";
            sql_update_query += TB_USERS;
            sql_update_query += " WHERE username = '" + username_entered + "'";
            sql_update_query += " AND special_word = '" + special_word_entered + "'";
            query.prepare(sql_update_query);


            //condition below is if condition fails to execute
            query.exec();

            if(query.next()){
                if(new_password == confirm_new_password){
                    if ((new_password.length() >= 8) && (password_has_number == true) && (password_has_Scharacter == true)){
                        QString sql_update_sentence = "UPDATE ";
                        sql_update_sentence += TB_USERS;
                        sql_update_sentence += " SET password = '" + password_coded + "'";
                        sql_update_sentence += " WHERE username = '" + username_entered + "'";

                        query.prepare(sql_update_sentence);
                        query.exec(sql_update_sentence);
                        hide();
                        MainWindow *main_window;
                        main_window = new MainWindow(this);
                        main_window->show();
                    }
                    else
                    {
                        QMessageBox::warning(this,"Error","password must have 8 characters or more and must contain  at least 1 number and 1 special character '!$%&*?#' ");
                    }

                }
                else
                {
                    QMessageBox::information(this,"Error","Passwords don't match");
                }
            }
            else
            {
                QMessageBox::information(this,"Error","Wrong username or special word");
            }
            query.finish();
        }
        else
        {
            QMessageBox::information(this,"Error","Database connection failed");
        }
    }
    else
    {
        QMessageBox::warning(this,"Error","You must fill in all the details");
    }
}

void ForgottenPassword::on_back_to_login_button_clicked()
{
    hide();
    MainWindow *main_window;
    main_window = new MainWindow(this);
    main_window->show();
}


QString ForgottenPassword::Encrypt(QString password_unencrypted, int key)
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


