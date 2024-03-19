#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

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
    *\brief This function updates the password with the password entered into the password input field if the password passes all the validation checks.
    */
    void update_password();

    /*!
    *\brief This function first name the first name with the first name entered into the first name input field.
    */
    void update_first_name();

    /*!
    *\brief This function last name the last name with the last name entered into the last name input field.
    */
    void update_last_name();

    /*!
    *\brief This function updates the email with the email entered into the email input field if the email passes all the validation checks.
    */
    void update_email();


    /*!
    *\brief Encrypts the user password using a Caesar cipher.
    *\param password_unencrypted
    *\param key
    *\return
    */
    QString Encrypt(QString password_unencrypted, int key);

    /*!
    *\brief This function updates the special_word with the special_word entered into the special_word input field if the special_word passes all the validation checks.
    */
    void update_special_word();

    /*!
    *\brief This function updates the username with the username entered into the username input field if the username passes all the validation checks.
    */
    void update_username();

    /*!
    *\brief This function opens a file browser for you to select a jpg image file. After the file has been selected, the users profile picture is updated in the application and on the database.
    */
    void on_browse_button_clicked();

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
    *\brief This function checks all the input fields, if they have data in them, it updates the database with the new information,
    * if it passes all the validation needed for each field.
    */
    void on_update_details_button_clicked();

    /*!
             * \brief This function checks if the global function dark_mode_toggle is set to be
             * Dark or light, sets to the opposite setting and then accordingly, displays the correct styling. Each UI element
             * is targeted and has its stylesheet set to either grey colours for dark mode or
             * white colours for the default light mode settings.
             */
    void on_accessibility_button_clicked();

    /*!
    *\brief This function checks if the input fields cursor position has changed, if so reset the inactivity settings
    */
    void on_new_username_cursorPositionChanged(int arg1, int arg2);

    /*!
    *\brief This function checks if the input fields cursor position has changed, if so reset the inactivity settings
    */
    void on_new_password_cursorPositionChanged(int arg1, int arg2);

    /*!
    *\brief This function checks if the input fields cursor position has changed, if so reset the inactivity settings
    */
    void on_new_first_name_cursorPositionChanged(int arg1, int arg2);

    /*!
    *\brief This function checks if the input fields cursor position has changed, if so reset the inactivity settings
    */
    void on_new_last_name_cursorPositionChanged(int arg1, int arg2);

    /*!
    *\brief This function checks if the input fields cursor position has changed, if so reset the inactivity settings
    */
    void on_new_email_cursorPositionChanged(int arg1, int arg2);

    /*!
    *\brief This function checks if the input fields cursor position has changed, if so reset the inactivity settings
    */
    void on_new_special_word_cursorPositionChanged(int arg1, int arg2);

    /*!
             * \brief This function checks if the global function dark_mode_toggle is set to be
             * Dark or light and then accordingly, displays the correct styling. Each UI element
             * is targeted and has its stylesheet set to either grey colours for dark mode or
             * white colours for the default light mode settings.
             */
    void set_accessibility_settings();

private:
    Ui::Settings *ui;
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

#endif // SETTINGS_H
