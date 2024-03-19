#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class AdminHome;
}

class AdminHome : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminHome(QWidget *parent = nullptr);
    ~AdminHome();

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
     * \brief This function is triggered upon clicking the home_button and it redirects the user to the
     * home page. The inactivity_timer is reset as the button has been clicked.
     */
    void on_home_button_clicked();


    /*!
     * \brief This function is triggered upon clicking the main_menu_button and it redirects the user
     * to the homepage. The inactivity_timer is reset as the button has been clicked and the group
     * manager is set to false to reset the page.
     */
    void on_main_menu_button_clicked();


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

private:
    Ui::AdminHome *ui;
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

#endif // ADMINHOME_H
