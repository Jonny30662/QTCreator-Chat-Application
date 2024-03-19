#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:


    void update_date_time();
    /*!
     * \brief login page is shown and the register page is hidden
     */

    void on_back_to_login_clicked();

    /*!
     * \brief Takes all of the user inputs into each lineedit, validates them by checking all details are filled in, makes sure the username is unique and password has at least 8 characters, special characters and a number. Once these have been confirmed they are saved to the database.
     */
    void on_register_button_clicked();

    /*!
     * \brief Closes the application
     */
    void on_shutdown_button_clicked();

    /*!
     * \brief Encrypts the user password using a Caesar cipher.
     * \param password_unencrypted
     * \param key
     * \return
     */
    QString Encrypt(QString password_unencrypted, int key);

private:
    Ui::Register *ui;
    QSqlDatabase database;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // REGISTER_H
