#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /*!
     * \The register page is displayed when this function is run and the login page is hidden.
     */
    void on_register_button_clicked();

    /*!
     * \The username and password entered are compared to the existing details in the database, if the details are correct then the home page will be displayed. When this also happens the username is loaded into a gloabal variable called 'current_user' as well as other details to make app features function.
     */
    void on_login_button_clicked();

    /*!
     * \Update time function simply updates the date and time label to the system date and time.
     */
    void update_date_time();

    /*!
     * \This function uses a caesar cipher to encrypt the entered user password in order to compare the result to the encrypted password in the database.
     * \param password_unencrypted is user password entered into the application
     * \param key is the encryption key used to encrypt the password.
     * \return returns the password encrypted
     */
    QString EncryptMain(QString password_unencrypted, int key);

    /*!
     * \brief This is used to decrypted the encryped values, works by putting the encrypted value back into the encrytion function except using the negative encrytpion key of what was used to encrypt the password in the first place. Used for testing purposes
     * \param password_encrypted is the encrypted password that needs to be decrypted (testing only)
     * \param key is opposite  encryption key used to encrypt the password
     * \return returns password decrypted
     */
    QString DecryptMain(QString password_encrypted, int key);

    /*!
     * \brief Opens the forgotten password page and hides the login page
     */
    void on_forgotten_password_button_clicked();

    /*!
     * \brief When the user has successfully logged in this function is called to retrieve the user profile pic from the database, which matches the users username.This image is loaded into the 'image' global variable.
     */
    void load_profile_picture();

    /*!
     * \brief When shutdown button clicked the application is closed.
     */
    void on_shutdown_button_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;

    /*!
     * \brief mousePressEvent
     * \param event
     */
    void mousePressEvent(QMouseEvent *event);

    /*!
     * \brief mouseMoveEvent
     * \param event
     */
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};
#endif // MAINWINDOW_H
