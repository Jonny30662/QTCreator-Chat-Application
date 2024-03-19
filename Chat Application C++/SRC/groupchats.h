#ifndef GROUPCHATS_H
#define GROUPCHATS_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class GroupChats;
}

class GroupChats : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroupChats(QWidget *parent = nullptr);
    ~GroupChats();

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
         * \brief This function checks if the current_account_type is set to Mod or Admin.
         * If the current_account_type is set to Admin then the main menu button is hidden
         * as the admin must not be able to message other users or join groups. However, if
         * the current_account_type is set to Mod then the main_menu_button is displayed as
         * Mods are able to message other users.
         */
    void check_account_type();

    /*!
    *\brief This function loads all the user accounts on the database apart from the admin account into a table,
    * two other columns are added to hold check boxes which allow users to be added into the group as well as also
    * having the option to make them moderators.
    */
    void load_user_accounts();

    /*!
    *\brief This function checks the table for the selected checkboxes, if the add useer checkbox is ticked,
    * the linked user is added to the group, if the moderator button is checked,
    * they are added to the group as a moderator, once all the users are added to the group,
    * the user who created the group is added as the group admin. Each time a new user needs to be added,
    * a function is called to add the user to the group in the database.
    */
    void on_create_group_button_clicked();

    /*!
    *\brief This function uses the data passed from on_create_button_clicked(); and uploads that data to the database.
    */
    void upload_to_database(int group_id, int user_id, QString user_type);

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
    *\brief This function resets the inactivity settings when a cell is clicked.
    */
    void on_add_remove_user_table_cellClicked(int row, int column);

    /*!
    *\brief This function resets the inactivity settings when the cursor position of the input
    * field has changed.
    */
    void on_set_group_name_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::GroupChats *ui;
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

#endif // GROUPCHATS_H
