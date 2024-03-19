#ifndef MESSAGINGPAGENEW_H
#define MESSAGINGPAGENEW_H
#include <QMqttClient>
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>
#include <QSslConfiguration>

namespace Ui {
class MessagingPageNew;
}

class MessagingPageNew : public QMainWindow
{
    Q_OBJECT

public:
    explicit MessagingPageNew(QWidget *parent = nullptr);
    ~MessagingPageNew();

private slots:
    /*!
             * \brief This function checks if the global function dark_mode_toggle is set to be
             * Dark or light and then accordingly, displays the correct styling. Each UI element
             * is targeted and has its stylesheet set to either grey colours for dark mode or
             * white colours for the default light mode settings.
             */
    void set_accessibility_settings();

        /*!
             * \brief This function is called every second that the timer adds one to it. Then,
             * inactive_seconds get added by 1 and once they add up to 60, inactive_minutes gets
             * set to 1. Lastly once inactive minutes add up to 15, then both inactive seconds and
             * minutes get reset back to 0 while, the on_logoff_button_clicked function gets called
             * and the user is automatically logged off and directed to the home page. This however,
             * is prevented if at any point the user clicks anywhere on the page.
             */
    void update_inactivity_status();

        /*!
             * \brief This function updates the current date and time dynamically every second.
             */
    void update_date_time();

    /*!
    *\brief This function checks the users permissions in a groupchat, if they are a group admin or moderator then they will be given additional permissions,
    * this is done by showing or hiding a button depending on the permissions available to the user.
    */
    void search_account_permissions();

    /*!
    *\brief This function checks the active status of the recipient if the user is privately messaging them and displays it to the user.
    * If the recipient is online, then it displays the UI element to 'Online', if they are offline, it displays the UI element to 'Offline'
    */
    void set_active_status();

    /*!
    *\brief This function updates the users UI with the message they want to send and sends it to the recipient. For updating the users UI,
    * the message is styled with a QTextBlockFormat to be left aligned and also styles the block to make message belonging more visible to the user.
    * If the user is messaging one user the message date and time are sent, if they are messaging a groupchat, it sends the message,
    * date and time and their username to show who sent the message in the groupchat.

    * The message is uploaded to the corressponding chat history table on the database, so the message history can be displayed to the user.
    */
    void on_send_button_clicked();

    /*!
    *\brief This function subscribes the MQTT client to the topic specified allowing the user to recieve messages. This uses topic selection using a
    * variable to decide on whether the topic the user should be listening to is their own topic or a groupchat topic. If they are in a groupchat,
    * they will listen to the groupchat topic, if they are messaging one user, they will listen to their own topic.

    * The subscribed topics are multi-level topics, these topics are filtered to only receive the correct topic in the chat everytime a message is received by the user.
    */
    void subscribe_user_to_topic();

    /*!
    *\brief This function checks if the recipient is one user or a group of users, this then allows for correct topic selection.
    * If the recipient is a group chat, the program will search for the users account permissions,
    * to check if they are an admin or moderator of the group chat before loading the chat history.
    * But if the recipient is just one user, the chat history will be loaded immediately
    */
    void check_recipient_type();

    /*!
    *\brief This functions gets the users chat history between them and the recipient when the UI loads and displays it to the user.
    * It requires two different SQL queries, the query is selected by checking the recipient type,
    * this will allow the program to load the correct chat history from the database.
    */
    void read_chat_history();

    /*!
         * \brief This function checks if the current_account_type is set to Mod or Admin.
         * If the current_account_type is set to Admin then the main menu button is hidden
         * as the admin must not be able to message other users or join groups. However, if
         * the current_account_type is set to Mod then the main_menu_button is displayed as
         * Mods are able to message other users.
         */
    void check_account_type();

    /*!
        *\brief This function hides the UI and shows the home page.
        */
    void on_home_button_clicked();

        /*!
        *\brief This function hides the UI and shows the chats page.
        */
    void on_chats_button_clicked();

        /*!
        *\brief This function hides the UI and shows the groups page.
        */
    void on_groups_button_clicked();

        /*!
        *\brief This function hides the UI and shows the accounts page.
        */
    void on_accounts_button_clicked();

        /*!
        *\brief This function hides the UI and shows the settings page.
        */
    void on_settings_button_clicked();

        /*!
        * \brief This function is triggered once the user manually clicks the shutdown_button. An SQL
        * query is run to set the current users active_status to 'Offline' as they have turned off the
        * application.
        */
    void on_shutdown_button_clicked();

        /*!
        *\brief This function hides the UI and shows the admin manage users page
        */
    void on_manage_users_button_clicked();

        /*!
        *\brief This function hides the UI and shows the admin manage groups page
        */
    void on_manage_groups_button_clicked();

        /*!
        *\brief This function hides the UI and shows the admin manage mods page
        */
    void on_manage_mods_button_clicked();

        /*!
        * \brief This function is triggered once the user manually clicks the logoff_button or once
        * the inactive_minutes global variable is = 15. An SQL query is run which sets the current
        * users inactive status to 'Offline' in the database whilst redirecting them to the login page.
        */
    void on_logoff_button_clicked();

    /*!
    *\brief This function hides the UI and shows the admin manage groups page, and sets a variable so it only allows group admin permissions
    */
    void on_group_button_clicked();

    /*!
        *\brief This function checks the input field for its cursor position, if it changes reset the inactivity settings.
        */
    void on_write_message_cursorPositionChanged();

private:
    Ui::MessagingPageNew *ui;
    QMqttClient *sdi_client;
    QSqlDatabase database;

    /*!
        *\brief This function checks for the user pressing mouse buttons, if so reset the inactivity settings
        */
    void mousePressEvent(QMouseEvent *event);

        /*!
        *\brief This function if the user has pressed their mouse button, they can move the window
        */
    void mouseMoveEvent(QMouseEvent *event);

        /*!
        *\brief This function checks for the user pressing keys, if so reset the inactivity settings
        */
    void keyPressEvent(QKeyEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // MESSAGINGPAGENEW_H
