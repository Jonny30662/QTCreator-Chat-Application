#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "adminhome.h"
#include "global_variables.hpp"
#include "project_database.h"
#include "forgottenpassword.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>
#include <homepage.h>
#include <QDateTime>
#include <QTimer>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void MainWindow::update_date_time()
{
    ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void MainWindow::on_register_button_clicked()
{
    hide();
    Register *rregister;
    rregister = new Register(this);
    rregister->show();
}

void MainWindow::on_login_button_clicked()
{
    QString username_entered = ui->username->text();
    QString password_entered = ui->password->text();
    QString password_entered_coded = EncryptMain(password_entered, 4);

    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    if ((!username_entered.isEmpty()) && (!password_entered.isEmpty())){
        if (database.open())
        {
            QSqlQuery sql_select_query(QSqlDatabase::database(DB_NAME));
            QString sql_login_user_query = "SELECT * FROM ";
            sql_login_user_query += TB_USERS;
            sql_login_user_query += " WHERE username = :username AND password = :password";
            sql_select_query.prepare(sql_login_user_query);

            sql_select_query.bindValue(":username", username_entered);
            sql_select_query.bindValue(":password", password_entered_coded);

            //condition below is if condition fails to execute
            sql_select_query.exec();

            if(sql_select_query.next()){
                current_user = username_entered;
                current_account_type = sql_select_query.value(8).toString();
                dark_mode_toggle = sql_select_query.value(10).toString();
                QString sql_update_sentence = "UPDATE ";
                sql_update_sentence += TB_USERS;
                sql_update_sentence += " SET active_status='Online' WHERE username = '" + current_user + "'";
                sql_select_query.prepare(sql_update_sentence);
                sql_select_query.exec(sql_update_sentence);
                hide(); //messaging page is hidden
                load_profile_picture();

                if (current_account_type == "Admin"){
                    AdminHome *admin_page;
                    admin_page = new AdminHome(this);
                    admin_page->show();
                }
                else
                {
                    HomePageNewest *home_page;
                    home_page = new HomePageNewest(this);
                    home_page->show();
                }
            }
            else
            {
                QMessageBox::information(this,"Error","Wrong password or username");
            }
            sql_select_query.finish();
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

    // This loop clear the line edits every single time, even if there are errors
    foreach(QLineEdit* le, findChildren<QLineEdit*>()){
        le->clear();
    }
    database.close();
}



void MainWindow::on_forgotten_password_button_clicked()
{
    hide();
    ForgottenPassword *forgotten_password;
    forgotten_password = new ForgottenPassword(this);
    forgotten_password->show();
}

QString MainWindow::EncryptMain(QString password_unencrypted, int key)
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
QString MainWindow::DecryptMain(QString password_encrypted, int key){
    return EncryptMain(password_encrypted, 26-key);

}

void MainWindow::load_profile_picture()
{
    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);
    if(database.open())
    {
        QModelIndex index;
        QSqlQueryModel model;
        QByteArray bytes;

        QSqlQuery query(database);

        QString str = "SELECT image FROM chat_users ";
        str += "WHERE username = '" + current_user + "'";
        query.prepare(str);

        if(query.exec()){
            //Set model
            model.setQuery(query);
            index = model.index(0,0);
            bytes = index.data().toByteArray();

            image.loadFromData(bytes);
            image = image.scaledToHeight(50, Qt::SmoothTransformation);
        }
    }
}

void MainWindow::on_shutdown_button_clicked()
{
    QCoreApplication::exit();
}
