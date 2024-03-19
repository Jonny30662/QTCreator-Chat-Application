#ifndef FORGOTTENPASSWORD_H
#define FORGOTTENPASSWORD_H

#include <QMainWindow>
#include <QMainWindow>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class ForgottenPassword;
}

class ForgottenPassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit ForgottenPassword(QWidget *parent = nullptr);
    ~ForgottenPassword();

private slots:
    /*!
             * \brief This function updates the current date and time dynamically every second.
             */
    void update_date_time();

    /*!
          * \brief This function is triggered once the user manually clicks the shutdown_button. An SQL
          * query is run to set the current users active_status to 'Offline' as they have turned off the
          * application.
          */
    void on_shutdown_button_clicked();

    /*!
        * \brief Validates the username and special word entered with the entries in the database,
        * then carries out the password validation.
        * After this the updated password is saved to the database.
        */
    void on_change_password_button_clicked();

    /*!
       *\brief Takes all of the user inputs into each lineedit, validates them by checking all details are filled in,
       * makes sure the username is unique and password has at least 8 characters, special characters and a number.
       * Once these have been confirmed they are saved to the database.
       */
    void on_back_to_login_button_clicked();

    /*!
       *\brief Encrypts the user password using a Caesar cipher.
       *\param password_unencrypted
       *\param key
       *\return
       */
    QString Encrypt(QString password_unencrypted, int key);

private:
    Ui::ForgottenPassword *ui;
    QSqlDatabase database;

    /*!
    *\brief This function checks for the user pressing mouse buttons, if so reset the inactivity settings
    */
    void mousePressEvent(QMouseEvent *event);

    /*!
        *\brief This function if the user has pressed their mouse button, they can move the window
        */
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // FORGOTTENPASSWORD_H
