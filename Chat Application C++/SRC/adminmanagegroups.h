#ifndef ADMINMANAGEGROUPS_H
#define ADMINMANAGEGROUPS_H

#include <QMainWindow>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class AdminManageGroups;
}

class AdminManageGroups : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminManageGroups(QWidget *parent = nullptr);
    ~AdminManageGroups();

private slots:
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
     * \brief This function simply checks if the group manager is set to true (meaning that
     * they were redirected to this page upon creating the manage groups button on the groups
     * page). It then hides the other admin pages as the group manager (both group adin and
     * group mod) should not be able to view other admin features as they are a group admin
     * and not the system admin.
     */
    void load_one_group();


    /*!
     * \brief This function displays the table showing information about users within the group
     * that the group manager chose to manage. Only one group is displayed in this function as an
     * admin of one group does not mean that they are the admin of the entire system. First, the
     * database is opened and error messages are shown if there is no connection. Then an SQL query
     * is run to select all the users within the current_recipient's group. The current user and
     * admin are not displayed as you should not be able to promote or demote yourself or the admin.
     * Upon the execution of the query, the users information are updated to the table. This page
     * also has two additional buttons the allow the group manager to promote or demote users within
     * their group.
     */
    void display_one_group();


    /*!
     * \brief Similarly to the display_one_group() function, this function displays the all of the
     * groups stored on the database. This function only gets called if the group_manager is set to
     * false meaning that the current_user must be the system admin
     */
    void display_all_groups();


    /*!
     * \brief This function first sets inactive_seconds and inactive_time to 0 as the user has been
     * active by selecting a user. It then displays the information of the selected_group_user into
     * the label which then allows the delete_button to set to true so that they can remove the group
     * and the remove_button is shown to allow the group_manager or system admin to remove individual
     * users from the group.
     * \param The row parameter is used to find the information of the user using the rows from the table
     * \param The column parameter is not used.
     */
    void on_tableWidget_cellClicked(int row, int column);


    /*!
     * \brief This function allows the group_manager and the system admin to delete the selected group
     * from the database. The group is deleted from both the groupchat_users and group_chats tables.
     */
    void on_delete_button_clicked();


    /*!
     * \brief This function allows the group_manager and the system admin to remove individual members
     * from the group(s).
     */
    void on_remove_button_clicked();


    /*!
     * \brief This function is triggered upon clicking the home_button and it redirects the user to the
     * home page. The inactivity_timer is reset as the button has been clicked.
     */
    void on_home_button_clicked();


    /*!
     * \brief This function is triggered upon clicking the manage_users_button and it redirects the user
     * to the adminManagesUsers page. The inactivity_timer is reset as the button has been clicked.
     */
    void on_manage_users_button_clicked();


    /*!
     * \brief This function is triggered upon clicking the manage_groups_button and it redirects the user
     * to the adminManagesGroups page. The inactivity_timer is reset as the button has been clicked.
     */
    void on_manage_groups_button_clicked();


    /*!
     * \brief This function is triggered upon clicking the manage_mods_button and it redirects the user
     * to the adminManagesMods page. The inactivity_timer is reset as the button has been clicked.
     */
    void on_manage_mods_button_clicked();


    /*!
     * \brief This function is triggered upon clicking the main_menu_button and it redirects the user
     * to the homepage. The inactivity_timer is reset as the button has been clicked and the group
     * manager is set to false to reset the page.
     */
    void on_main_menu_button_clicked();


    /*!
     * \brief This function is triggered once the user manually clicks the logoff_button or once
     * the inactive_minutes global variable is = 15. An SQL query is run which sets the current
     * users inactive status to 'Offline' in the database whilst redirecting them to the login page.
     */
    void on_logoff_button_clicked();


    /*!
     * \brief This function is triggered once the user manually clicks the shutdown_button. An SQL
     * query is run to set the current users active_status to 'Offline' as they have turned off the
     * application.
     */
    void on_shutdown_button_clicked();


    /*!
     * \brief This function allows the group_manager to promote users to moderators of their own group.
     * An SQL query is run to update their user_type to 'Mod'.
     */
    void on_promote_button_clicked();


    /*!
     * \brief This function allows the group_manager to demote users from being moderators of their group.
     * An SQL query is run to update their user_type to 'Mod'.
     */
    void on_demote_button_clicked();

private:

    Ui::AdminManageGroups *ui;
    QSqlDatabase database;
    /*!
     * \brief checks if the group_manager if false for which it then displays all the groups however, if the
     * group_manager is true it will display only their current group.
     */
    void readDBandDisplayTable();

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

#endif // ADMINMANAGEGROUPS_H
