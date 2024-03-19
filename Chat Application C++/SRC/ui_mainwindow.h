/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *topPanel;
    QHBoxLayout *horizontalLayout;
    QLabel *current_date_time;
    QSpacerItem *horizontalSpacer;
    QPushButton *shutdown_button;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *loginForm;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *sername_label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_4;
    QLabel *password_label;
    QLineEdit *password;
    QSpacerItem *verticalSpacer_2;
    QPushButton *login_button;
    QPushButton *register_button;
    QPushButton *forgotten_password_button;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topPanel = new QWidget(centralwidget);
        topPanel->setObjectName(QString::fromUtf8("topPanel"));
        topPanel->setStyleSheet(QString::fromUtf8("#topPanel { \n"
" background-color: DimGrey; \n"
" border-radius: 8px;\n"
"}\n"
"QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }\n"
""));
        horizontalLayout = new QHBoxLayout(topPanel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        current_date_time = new QLabel(topPanel);
        current_date_time->setObjectName(QString::fromUtf8("current_date_time"));
        current_date_time->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout->addWidget(current_date_time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        shutdown_button = new QPushButton(topPanel);
        shutdown_button->setObjectName(QString::fromUtf8("shutdown_button"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shutdown_button->sizePolicy().hasHeightForWidth());
        shutdown_button->setSizePolicy(sizePolicy);
        shutdown_button->setMinimumSize(QSize(55, 55));
        shutdown_button->setCursor(QCursor(Qt::PointingHandCursor));
        shutdown_button->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #e11c2d; }\n"
"QPushButton:hover { background-color: #CE0000; }"));

        horizontalLayout->addWidget(shutdown_button);


        verticalLayout->addWidget(topPanel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        loginForm = new QWidget(centralwidget);
        loginForm->setObjectName(QString::fromUtf8("loginForm"));
        sizePolicy.setHeightForWidth(loginForm->sizePolicy().hasHeightForWidth());
        loginForm->setSizePolicy(sizePolicy);
        loginForm->setMinimumSize(QSize(350, 200));
        loginForm->setStyleSheet(QString::fromUtf8("#loginForm { \n"
"background-color: LightGrey;\n"
"border-radius: 8px;\n"
"\n"
"}\n"
"QLabel{ color:black;}\n"
"QPushButton {\n"
"    color: DimGrey;\n"
"    background-color: White;\n"
"    border-width: 0px;\n"
"    border-radius: 2px;\n"
"}\n"
"QPushButton:hover { \n"
"	background-color: DarkOrange;\n"
"	color: white;\n"
" \n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(loginForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(35, 35, 35, 35);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        sername_label = new QLabel(loginForm);
        sername_label->setObjectName(QString::fromUtf8("sername_label"));
        sername_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_5->addWidget(sername_label);

        username = new QLineEdit(loginForm);
        username->setObjectName(QString::fromUtf8("username"));
        username->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_5->addWidget(username);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        password_label = new QLabel(loginForm);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_4->addWidget(password_label);

        password = new QLineEdit(loginForm);
        password->setObjectName(QString::fromUtf8("password"));
        password->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(password);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        login_button = new QPushButton(loginForm);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setMinimumSize(QSize(0, 40));
        login_button->setCursor(QCursor(Qt::PointingHandCursor));
        login_button->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(login_button);

        register_button = new QPushButton(loginForm);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setMinimumSize(QSize(0, 40));
        register_button->setCursor(QCursor(Qt::PointingHandCursor));
        register_button->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(register_button);

        forgotten_password_button = new QPushButton(loginForm);
        forgotten_password_button->setObjectName(QString::fromUtf8("forgotten_password_button"));
        forgotten_password_button->setMinimumSize(QSize(0, 40));
        forgotten_password_button->setCursor(QCursor(Qt::PointingHandCursor));
        forgotten_password_button->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(forgotten_password_button);


        horizontalLayout_3->addWidget(loginForm);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        sername_label->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        password_label->setText(QApplication::translate("MainWindow", "Password:", nullptr));
        password->setText(QString());
        login_button->setText(QApplication::translate("MainWindow", "login", nullptr));
        register_button->setText(QApplication::translate("MainWindow", "Register", nullptr));
        forgotten_password_button->setText(QApplication::translate("MainWindow", "Forgot Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
