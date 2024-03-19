#ifndef HOMEPAGENEWEST_H
#define HOMEPAGENEWEST_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class HomePageNewest;
}

class HomePageNewest : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePageNewest(QWidget *parent = nullptr);
    ~HomePageNewest();

private slots:
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
         * \brief This function checks if the current_account_type is set to Mod or Admin.
         * If the current_account_type is set to Admin then the main menu button is hidden
         * as the admin must not be able to message other users or join groups. However, if
         * the current_account_type is set to Mod then the main_menu_button is displayed as
         * Mods are able to message other users.
         */
    void check_account_type();


    /*!
         * \brief This function updates the current date and time dynamically every second.
         */
    void update_date_time();

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
             * \brief This function checks if the global function dark_mode_toggle is set to be
             * Dark or light and then accordingly, displays the correct styling. Each UI element
             * is targeted and has its stylesheet set to either grey colours for dark mode or
             * white colours for the default light mode settings.
             */
    void set_accessibility_settings();

private:
    Ui::HomePageNewest *ui;
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

#endif // HOMEPAGENEWEST_H
