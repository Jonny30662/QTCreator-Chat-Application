#include "messagingpage.h"
#include "global_variables.hpp"
#include "homepage.h"
#include "settings.h"
#include "groups.h"
#include "accounts.h"
#include "project_database.h"
#include "ui_messagingpage.h"
#include "existingchats.h"
#include "QTimer"
#include "QDateTime"
#include "adminmanageusers.h"
#include "adminmanagegroups.h"
#include "adminmanagemods.h"
#include "mainwindow.h"

#include <QMessageBox>

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>

bool groupchat = false;
bool first_run = true;
QTimer *subscribe_to_topic;
QTimer *set_recipient_type;
QTimer *update_active_status;

MessagingPageNew::MessagingPageNew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MessagingPageNew)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->shutdown_button->setIcon(QIcon("shutdown.png"));
    ui->shutdown_button->setIconSize(QSize(45, 50));

    ui->logoff_button->setIcon(QIcon("logoff.png"));
    ui->logoff_button->setIconSize(QSize(45, 50));

    ui->account_name->setText(current_user);
    ui->recipient_name->setText(current_recipient);
    ui->profile_pic->setPixmap(QPixmap::fromImage(image).scaledToWidth(ui->profile_pic->width(), Qt::SmoothTransformation));
    ui->group_button->hide();
    ui->active_status->hide();

    set_accessibility_settings();

    database = QSqlDatabase::addDatabase(SQLDB);
    database.setHostName(HOST);
    database.setUserName(USER);
    database.setPassword(PASSWORD);
    database.setDatabaseName(DB_NAME);

    //MQTT
    QString host = ("9a022894c16f4daa9d9a0a0f9487f56b.s1.eu.hivemq.cloud");
    int port = 8883;

    QSslConfiguration config;

    sdi_client = new QMqttClient(this);
    sdi_client->setHostname(host); //sets ip host address from ui textbox
    sdi_client->setPort(port); //sets port from ui spinbox

    config.defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    sdi_client -> setUsername("SDI_GROUP_16");
    sdi_client -> setPassword("SDI_password_16");
    sdi_client->connectToHostEncrypted();

    if(current_user != "username")
    {
        QTimer *update;
        update = new QTimer();
        QObject::connect(update, SIGNAL(timeout()),this, SLOT(update_date_time()));
        update->start(100);

        set_recipient_type = new QTimer(this);
        connect(set_recipient_type, SIGNAL(timeout()), this, SLOT(check_recipient_type()));
        set_recipient_type->start(500);

        update_active_status = new QTimer(this);
        connect(update_active_status, SIGNAL(timeout()), this, SLOT(set_active_status()));
        update_active_status->start(500); //time specified in ms

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

    subscribe_to_topic = new QTimer(this);
    connect(subscribe_to_topic, SIGNAL(timeout()), this, SLOT(subscribe_user_to_topic()));
    subscribe_to_topic->start(2500); //time specified in ms

    connect(sdi_client, &QMqttClient::messageReceived, [this](const QByteArray &message, const QMqttTopicName &topic)
    {
        if(topic == "sdi16client/" + current_user + "/" + current_recipient + "/pm" || topic != "sdi16client/" + current_recipient + "/" + current_user + "/gc")
        {
            if(message != ui->write_message->toPlainText()) //detects the message being received from other user
            {
                const QString messageContent = message;

                QTextCursor ui_cursor = ui->display_messages->textCursor();
                QTextBlockFormat alignText = ui_cursor.blockFormat();
                alignText.setAlignment(Qt::AlignRight);
                ui_cursor.mergeBlockFormat(alignText);
                alignText.setBackground(QBrush(Qt::lightGray));
                alignText.setLeftMargin(275);
                alignText.setRightMargin(0);
                ui_cursor.setBlockFormat(alignText);


                ui->display_messages->setTextCursor(ui_cursor);
                ui->display_messages->setFont(QFont("helvetica", 12, true));
                ui->display_messages->append(messageContent);//Displays messages into message log box on ui

                if(dark_mode_toggle == "Light")
                {
                    alignText.setBackground(QBrush(Qt::white));
                }
                else if(dark_mode_toggle == "Dark")
                {
                    alignText.setBackground(QBrush(Qt::darkGray));
                }
                ui_cursor.setBlockFormat(alignText);
                ui->display_messages->append("");
            }
        }
    });
}

MessagingPageNew::~MessagingPageNew()
{
    delete ui;
}

void MessagingPageNew::update_inactivity_status()
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

void MessagingPageNew::keyPressEvent(QKeyEvent *event)
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}

void MessagingPageNew::mousePressEvent(QMouseEvent *event) {
    inactive_seconds = 0;
    inactive_minutes = 0;
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MessagingPageNew::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void MessagingPageNew::read_chat_history()
{
    int chat_id;
    if (database.open())
    {
        if(groupchat == false)
        {
            QSqlQuery query(QSqlDatabase::database(DB_NAME));
            QString sql_sentence = "SELECT ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_id FROM ";
            sql_sentence += TB_USERS;
            sql_sentence += " INNER JOIN ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += " ON ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_one = ";
            sql_sentence += TB_USERS;
            sql_sentence += ".username";
            sql_sentence += " OR ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_two = ";
            sql_sentence += TB_USERS;
            sql_sentence += ".username";
            sql_sentence += " WHERE ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_one = :chat_user_one AND ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_two = :chat_user_two";
            sql_sentence += " OR ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_one = :chat_user_two AND ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_two = :chat_user_one";

            query.prepare(sql_sentence);

            query.bindValue(":chat_user_one", current_user);
            query.bindValue(":chat_user_two", current_recipient);

            query.exec();

            if(query.next())
            {
                chat_id = query.value(0).toInt();
            }

            query.finish();

            sql_sentence = "SELECT * FROM ";
            sql_sentence += TB_CHATHISTORY;ui->group_button->hide();
            sql_sentence += " WHERE chat_id = :chat_id ORDER BY date_and_time";

            query.prepare(sql_sentence);
            query.bindValue(":chat_id", chat_id);
            query.exec();
            ui->group_button->hide();
            while(query.next())
            {
                if(query.value(2) == current_user)
                {
                    QString messageContent = query.value(4).toString();
                    QTextCursor ui_cursor = ui->display_messages->textCursor();
                    QTextBlockFormat alignText = ui_cursor.blockFormat();
                    alignText.setAlignment(Qt::AlignLeft);
                    ui_cursor.mergeBlockFormat(alignText);

                    alignText.setBackground(QBrush(Qt::lightGray));
                    alignText.setLeftMargin(0);
                    alignText.setRightMargin(275);
                    ui_cursor.setBlockFormat(alignText);


                    ui->display_messages->setTextCursor(ui_cursor);
                    ui->display_messages->setFont(QFont("helvetica", 12, true));
                    ui->display_messages->append(messageContent);//Displays messages into message log box on ui

                    if(dark_mode_toggle == "Light")
                    {
                        alignText.setBackground(QBrush(Qt::white));
                    }
                    else if(dark_mode_toggle == "Dark")
                    {
                        alignText.setBackground(QBrush(Qt::darkGray));
                    }
                    ui_cursor.setBlockFormat(alignText);
                    ui->display_messages->append("");
                }
                else
                {
                    QString messageContent = query.value(4).toString();
                    QTextCursor ui_cursor = ui->display_messages->textCursor();
                    QTextBlockFormat alignText = ui_cursor.blockFormat();
                    alignText.setAlignment(Qt::AlignRight);
                    ui_cursor.mergeBlockFormat(alignText);
                    alignText.setBackground(QBrush(Qt::lightGray));
                    alignText.setLeftMargin(275);
                    alignText.setRightMargin(0);
                    ui_cursor.setBlockFormat(alignText);


                    ui->display_messages->setTextCursor(ui_cursor);
                    ui->display_messages->setFont(QFont("helvetica", 12, true));
                    ui->display_messages->append(messageContent);//Displays messages into message log box on ui

                    if(dark_mode_toggle == "Light")
                    {
                        alignText.setBackground(QBrush(Qt::white));
                    }
                    else if(dark_mode_toggle == "Dark")
                    {
                        alignText.setBackground(QBrush(Qt::darkGray));
                    }
                    ui_cursor.setBlockFormat(alignText);
                    ui->display_messages->append("");
                }
            }

            query.finish();
        }
        else if(groupchat == true)
        {
            QSqlQuery read_groupchat_history(QSqlDatabase::database(DB_NAME));
            QString sql_sentence = "SELECT ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += ".groupchat_id FROM ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += " WHERE ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += ".groupchat_name = :recipient_name";
            read_groupchat_history.prepare(sql_sentence);

            read_groupchat_history.bindValue(":recipient_name", current_recipient);

            read_groupchat_history.exec();

            if(read_groupchat_history.next())
            {
                chat_id = read_groupchat_history.value(0).toInt();
                read_groupchat_history.finish();
            }

            sql_sentence = "SELECT ";
            sql_sentence += TB_GROUPCHATHISTORY;
            sql_sentence += ".* FROM ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += " INNER JOIN ";
            sql_sentence += TB_GROUPCHATHISTORY;
            sql_sentence += " ON ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += ".groupchat_id = ";
            sql_sentence += TB_GROUPCHATHISTORY;
            sql_sentence += ".groupchat_id";
            sql_sentence += " WHERE ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += ".groupchat_id = :groupchat_id";
            sql_sentence += " ORDER BY ";
            sql_sentence += TB_GROUPCHATHISTORY;
            sql_sentence += ".date_and_time";

            read_groupchat_history.prepare(sql_sentence);

            read_groupchat_history.bindValue(":groupchat_id", chat_id);

            read_groupchat_history.exec();

            while(read_groupchat_history.next())
            {
                if(read_groupchat_history.value(2) == current_user)
                {
                    QString messageContent = read_groupchat_history.value(4).toString();
                    QTextCursor ui_cursor = ui->display_messages->textCursor();
                    QTextBlockFormat alignText = ui_cursor.blockFormat();
                    alignText.setAlignment(Qt::AlignLeft);
                    ui_cursor.mergeBlockFormat(alignText);
                    alignText.setBackground(QBrush(Qt::lightGray));
                    alignText.setLeftMargin(0);
                    alignText.setRightMargin(275);
                    ui_cursor.setBlockFormat(alignText);


                    ui->display_messages->setTextCursor(ui_cursor);
                    ui->display_messages->setFont(QFont("helvetica", 12, true));
                    ui->display_messages->append(messageContent);//Displays messages into message log box on ui

                    if(dark_mode_toggle == "Light")
                    {
                        alignText.setBackground(QBrush(Qt::white));
                    }
                    else if(dark_mode_toggle == "Dark")
                    {
                        alignText.setBackground(QBrush(Qt::darkGray));
                    }
                    ui_cursor.setBlockFormat(alignText);
                    ui->display_messages->append("");
                }
                else
                {
                    QString messageContent = read_groupchat_history.value(4).toString();
                    QTextCursor ui_cursor = ui->display_messages->textCursor();
                    QTextBlockFormat alignText = ui_cursor.blockFormat();
                    alignText.setAlignment(Qt::AlignRight);
                    ui_cursor.mergeBlockFormat(alignText);
                    alignText.setBackground(QBrush(Qt::lightGray));
                    alignText.setLeftMargin(275);
                    alignText.setRightMargin(0);
                    ui_cursor.setBlockFormat(alignText);


                    ui->display_messages->setTextCursor(ui_cursor);
                    ui->display_messages->setFont(QFont("helvetica", 12, true));
                    ui->display_messages->append(messageContent);//Displays messages into message log box on ui

                    if(dark_mode_toggle == "Light")
                    {
                        alignText.setBackground(QBrush(Qt::white));
                    }
                    else if(dark_mode_toggle == "Dark")
                    {
                        alignText.setBackground(QBrush(Qt::darkGray));
                    }
                    ui_cursor.setBlockFormat(alignText);
                    ui->display_messages->append("");
                }
            }

            read_groupchat_history.finish();
        }
        database.close();
    }
}

void MessagingPageNew::search_account_permissions()
{
    if(database.open())
    {
        QSqlQuery groupchat_account_types(QSqlDatabase::database(DB_NAME));
        QString sql_sentence = "SELECT groupchat_users.user_type FROM ";
        sql_sentence += TB_GROUPCHATS;
        sql_sentence += " INNER JOIN ";
        sql_sentence += TB_GROUPMEMBERS;
        sql_sentence += " ON ";
        sql_sentence += TB_GROUPCHATS ;
        sql_sentence += ".groupchat_id = ";
        sql_sentence += TB_GROUPMEMBERS;
        sql_sentence += ".group_id ";
        sql_sentence += " INNER JOIN ";
        sql_sentence += TB_USERS;
        sql_sentence += " ON ";
        sql_sentence += TB_USERS ;
        sql_sentence += ".user_id = ";
        sql_sentence += TB_GROUPMEMBERS;
        sql_sentence += ".user_id ";
        sql_sentence += "WHERE ";
        sql_sentence += TB_GROUPCHATS;
        sql_sentence += ".groupchat_name = :groupchat_name AND ";
        sql_sentence += TB_USERS;
        sql_sentence += ".username LIKE :username;";

        groupchat_account_types.prepare(sql_sentence);
        groupchat_account_types.bindValue(":groupchat_name", current_recipient);
        groupchat_account_types.bindValue(":username", current_user);

        groupchat_account_types.exec();

        if(groupchat_account_types.next())
        {
            if((groupchat_account_types.value(0) == "Admin")|| (groupchat_account_types.value(0) == "Mod"))
            {
                ui->group_button->show();
            }
            else
            {
                ui->group_button->hide();
            }
        }

    }

}

void MessagingPageNew::set_active_status()
{
    if(groupchat == false)
    {
        if (database.open())
        {

            QSqlQuery query(QSqlDatabase::database(DB_NAME));
            QString sql_sentence ="SELECT active_status FROM ";
            sql_sentence += DB_NAME;
            sql_sentence += ".";
            sql_sentence += TB_USERS;
            sql_sentence += " WHERE username = :recipient_username";
            query.prepare(sql_sentence);

            query.bindValue(":recipient_username", current_recipient);
            if(query.exec())
            {
                query.first();
                QString active_status_data = query.value(0).toString();
                ui->active_status->setText(active_status_data);
                ui->active_status->show();
                query.finish();
            }
        }
    }
    else
    {
        ui->active_status->hide();
        update_active_status->stop();
    }

    database.close();

}

void MessagingPageNew::update_date_time()
{
    ui->current_date_time->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy" "      hh:mm:ss"));
}

void MessagingPageNew::check_account_type(){
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

void MessagingPageNew::on_send_button_clicked() //private messaging still needs changing, people outside of a private conversation cant see the other peoples conversations but can still publish to them
{
    inactive_seconds = 0;
    inactive_minutes = 0;

    QString topic;
    QString publishMessage;
    QString messageContent;

    if(groupchat == false)
    {
        topic = ("sdi16client/" + current_recipient + "/" + current_user + "/pm");
    }
    else if(groupchat == true)
    {
        topic = ("sdi16client/" + current_recipient + "/" + current_user + "/gc");
    }


    if (ui->write_message->toPlainText().isEmpty())
    {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("No message to send")); //returns error if message cannot be published
        return;
    }
    else
    {
        QDate curDate = QDate::currentDate();
        QTime curTime = QTime::currentTime();

        publishMessage = ui->write_message->toPlainText() + QLatin1Char('\n')
                + curDate.toString("dd MMM yy") + QLatin1Char(' ') //date to string, adds to 'messageContent'. uses custom settings to display the date
                + curTime.toString("h:mm ap") + QLatin1Char('\n');//time to string, adds to 'messageContent'. uses custom settings to display the time
        if(groupchat == true)
        {
            publishMessage += current_user + "\n";
        }

        if (sdi_client->publish(topic, publishMessage.toUtf8()) == -1) //Publishes message to topic
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message")); //returns error if message cannot be published

        messageContent = ui->write_message->toPlainText() + QLatin1Char('\n')//adds received message to 'messageContent'
                + curDate.toString("dd MMM yy") + QLatin1Char(' ') //date to string, adds to 'messageContent'. uses custom settings to display the date
                + curTime.toString("h:mm ap") + QLatin1Char('\n'); //time to string, adds to 'messageContent'. uses custom settings to display the time

        QTextCursor ui_cursor = ui->display_messages->textCursor();
        QTextBlockFormat alignText = ui_cursor.blockFormat();
        alignText.setAlignment(Qt::AlignLeft);
        ui_cursor.mergeBlockFormat(alignText);
        alignText.setBackground(QBrush(Qt::lightGray));
        alignText.setLeftMargin(0);
        alignText.setRightMargin(275);
        ui_cursor.setBlockFormat(alignText);

        ui->display_messages->setTextCursor(ui_cursor);
        ui->display_messages->setFont(QFont("helvetica", 12, true));
        ui->display_messages->append(messageContent);//Displays messages into message log box on ui

        if(dark_mode_toggle == "Light")
        {
            alignText.setBackground(QBrush(Qt::white));
        }
        else if(dark_mode_toggle == "Dark")
        {
            alignText.setBackground(QBrush(Qt::darkGray));
        }
        ui_cursor.setBlockFormat(alignText);
        ui->display_messages->append("");

        ui->write_message->setText(""); //clears text from 'messageEdit'

    }

    int chat_id;
    if (database.open())
    {
        if(groupchat == false)
        {
            QSqlQuery query(QSqlDatabase::database(DB_NAME));
            QString sql_sentence = "SELECT ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_id FROM ";
            sql_sentence += TB_USERS;
            sql_sentence += " INNER JOIN ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += " ON ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_one = ";
            sql_sentence += TB_USERS;
            sql_sentence += ".username";
            sql_sentence += " OR ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_two = ";
            sql_sentence += TB_USERS;
            sql_sentence += ".username";
            sql_sentence += " WHERE ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_one = :chat_user_one AND ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_two = :chat_user_two";
            sql_sentence += " OR ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_one = :chat_user_two AND ";
            sql_sentence += TB_EXISTINGCHATS;
            sql_sentence += ".chat_user_two = :chat_user_one";

            query.prepare(sql_sentence);
            query.bindValue(":chat_user_one", current_user);
            query.bindValue(":chat_user_two", current_recipient);
            query.exec();

            if(query.next())
            {
                chat_id = query.value(0).toInt();
            }

            query.finish();

            sql_sentence = "INSERT INTO ";
            sql_sentence += TB_CHATHISTORY;
            sql_sentence += " (chat_id, sent_by, received_by, message_contents) VALUES (:chat_id, :sent_by, :received_by, :message_contents)";

            query.prepare(sql_sentence);

            query.bindValue(":chat_id", chat_id);
            query.bindValue(":sent_by", current_user);
            query.bindValue(":received_by", current_recipient);
            query.bindValue(":message_contents", messageContent);

            query.exec();

            query.finish();
        }
        else if(groupchat == true)
        {
            QSqlQuery upload_groupchat_history(QSqlDatabase::database(DB_NAME));
            QString sql_sentence = "SELECT ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += ".groupchat_id FROM ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += " WHERE ";
            sql_sentence += TB_GROUPCHATS;
            sql_sentence += ".groupchat_name = :recipient_name";
            upload_groupchat_history.prepare(sql_sentence);

            upload_groupchat_history.bindValue(":recipient_name", current_recipient);

            upload_groupchat_history.exec();

            if(upload_groupchat_history.next())
            {
                chat_id = upload_groupchat_history.value(0).toInt();
                upload_groupchat_history.finish();
            }

            sql_sentence = "INSERT INTO ";
            sql_sentence += TB_GROUPCHATHISTORY;
            sql_sentence += " (groupchat_id, sent_by, receiving_groupchat, message_contents) VALUES (:groupchat_id, :sent_by, :receiving_groupchat, :message_contents)";

            upload_groupchat_history.prepare(sql_sentence);

            upload_groupchat_history.bindValue(":groupchat_id", chat_id);
            upload_groupchat_history.bindValue(":sent_by", current_user);
            upload_groupchat_history.bindValue(":receiving_groupchat", current_recipient);
            upload_groupchat_history.bindValue(":message_contents", publishMessage);

            upload_groupchat_history.exec();
        }
        database.close();
    }
}

void MessagingPageNew::subscribe_user_to_topic()
{
    QString topic;

    if(groupchat == false)
    {
        topic = ("sdi16client/" + current_user + "/#");
    }
    else if(groupchat == true)
    {
        topic = ("sdi16client/" + current_recipient + "/#");
    }

    auto subscription = sdi_client->subscribe(topic);
    if(!subscription)
    {
        if(first_run != true)
        {
            QMessageBox::critical(this,QLatin1String("Error"), QLatin1String("Could not subscribe. Check connection"));
            return;
        }
        else
        {
            first_run = false;
        }
    }
    else if(subscription)
    {
        subscribe_to_topic->stop();
    }

}

void MessagingPageNew::check_recipient_type()
{
    if (database.open())
    {
        QSqlQuery query(QSqlDatabase::database(DB_NAME));
        QString sql_sentence = "SELECT username FROM ";
        sql_sentence += TB_USERS;
        sql_sentence += " WHERE username = :recipient_name;";

        query.prepare(sql_sentence);
        query.bindValue(":recipient_name", current_recipient);
        query.exec();

        if(query.next())
        {
            groupchat = false;
        }
        else
        {
            groupchat = true;
            ui->active_status->hide();
            search_account_permissions();
        }

        set_recipient_type->stop();
        read_chat_history();

        query.finish();
        database.close();
    }
}

void MessagingPageNew::on_home_button_clicked()
{
    inactivity_timer->stop();
    hide();
    HomePageNewest *home_page_newest;
    home_page_newest = new HomePageNewest(this);
    home_page_newest->show();
}

void MessagingPageNew::on_chats_button_clicked()
{
    inactivity_timer->stop();
    hide();
    ExistingChats *existing_chats;
    existing_chats = new ExistingChats(this);
    existing_chats->show();
}

void MessagingPageNew::on_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Groups *groups;
    groups = new Groups(this);
    groups->show();
}

void MessagingPageNew::on_accounts_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Accounts *accounts;
    accounts = new Accounts(this);
    accounts->show();
}

void MessagingPageNew::on_settings_button_clicked()
{
    inactivity_timer->stop();
    hide();
    Settings *settings;
    settings = new Settings(this);
    settings->show();
}

void MessagingPageNew::on_manage_users_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageUsers *admin_m_users;
    admin_m_users = new  AdminManageUsers(this);
    admin_m_users->show();
}

void MessagingPageNew::on_manage_groups_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();
}

void MessagingPageNew::on_manage_mods_button_clicked()
{
    inactivity_timer->stop();
    hide();
    AdminManageMods *admin_m_mods;
    admin_m_mods = new  AdminManageMods(this);
    admin_m_mods->show();
}

void MessagingPageNew::on_shutdown_button_clicked()
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

void MessagingPageNew::on_logoff_button_clicked()
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

void MessagingPageNew::on_group_button_clicked()
{
    group_manager = true;
    inactivity_timer->stop();
    hide();
    AdminManageGroups *admin_m_groups;
    admin_m_groups = new  AdminManageGroups(this);
    admin_m_groups->show();

    group_manager = true;
}

void MessagingPageNew::on_write_message_cursorPositionChanged()
{
    inactive_seconds = 0;
    inactive_minutes = 0;
}


void MessagingPageNew::set_accessibility_settings()
{
    if(dark_mode_toggle == "Dark"){
        QString white_colour = "white";
        QString grey_colour = "Grey";
        QString dim_grey_colour = "DimGrey";
        QString light_grey_colour = "lightGrey";

        ui->central_widget->setStyleSheet("#central_widget { background-color: " + grey_colour + ";}");

        ui->display_messages->setStyleSheet("#display_messages { background-color: " + grey_colour + "; color: " + white_colour + ";}");
        ui->group_button->setStyleSheet("#group_button { background-color: " + grey_colour + "; color: " + white_colour + ";}");
        ui->send_button->setStyleSheet("#send_button { background-color: " + grey_colour + "; color: " + white_colour + ";}");
        ui->write_message->setStyleSheet("#write_button { background-color: " + grey_colour + "; color: " + white_colour + ";}");

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

        ui->page_contents_widget->setStyleSheet("#page_contents_widget { background-color: " + grey_colour + "; border-radius: 8px;}");
        ui->page_contents_widget_2->setStyleSheet("#page_contents_widget_2 { background-color: " + grey_colour + "; border-radius: 8px;}");
    }

    else{
        ui->central_widget->setStyleSheet("");
        ui->page_contents_widget->setStyleSheet("#page_contents_widget { \n background-color: white;\n border-radius: 8px;\n}");
        ui->page_contents_widget_2->setStyleSheet("#page_contents_widget_2 { \n background-color: white;\n border-radius: 8px;\n}");
        ui->display_messages->setStyleSheet("");
        ui->group_button->setStyleSheet("");
        ui->send_button->setStyleSheet("");
        ui->write_message->setStyleSheet("");
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
    }
}
