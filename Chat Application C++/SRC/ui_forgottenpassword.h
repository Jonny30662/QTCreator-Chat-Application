/********************************************************************************
** Form generated from reading UI file 'forgottenpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTTENPASSWORD_H
#define UI_FORGOTTENPASSWORD_H

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

class Ui_ForgottenPassword
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *topPanel;
    QHBoxLayout *horizontalLayout;
    QLabel *current_date_time;
    QSpacerItem *horizontalSpacer;
    QPushButton *shutdown_button;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *forgot_password_form;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *username_label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_6;
    QLabel *special_word_label;
    QLineEdit *special_word;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *new_password_label;
    QLineEdit *new_password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *confirm_new_password_label;
    QLineEdit *confirm_new_password;
    QSpacerItem *verticalSpacer_4;
    QPushButton *change_password_button;
    QPushButton *back_to_login_button;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ForgottenPassword)
    {
        if (ForgottenPassword->objectName().isEmpty())
            ForgottenPassword->setObjectName(QString::fromUtf8("ForgottenPassword"));
        ForgottenPassword->resize(800, 600);
        centralwidget = new QWidget(ForgottenPassword);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topPanel = new QWidget(centralwidget);
        topPanel->setObjectName(QString::fromUtf8("topPanel"));
        topPanel->setStyleSheet(QString::fromUtf8("#topPanel { \n"
" background-color: DimGrey; \n"
" border-radius: 8px;\n"
"}\n"
"QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
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
        shutdown_button->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #e11c2d; }\n"
"QPushButton:hover { background-color: #CE0000; }"));

        horizontalLayout->addWidget(shutdown_button);


        verticalLayout->addWidget(topPanel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, 0, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        forgot_password_form = new QWidget(centralwidget);
        forgot_password_form->setObjectName(QString::fromUtf8("forgot_password_form"));
        forgot_password_form->setStyleSheet(QString::fromUtf8("#forgot_password_form { \n"
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
""));
        verticalLayout_2 = new QVBoxLayout(forgot_password_form);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(35, 35, 35, 35);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        username_label = new QLabel(forgot_password_form);
        username_label->setObjectName(QString::fromUtf8("username_label"));

        horizontalLayout_4->addWidget(username_label);

        username = new QLineEdit(forgot_password_form);
        username->setObjectName(QString::fromUtf8("username"));

        horizontalLayout_4->addWidget(username);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        special_word_label = new QLabel(forgot_password_form);
        special_word_label->setObjectName(QString::fromUtf8("special_word_label"));

        horizontalLayout_6->addWidget(special_word_label);

        special_word = new QLineEdit(forgot_password_form);
        special_word->setObjectName(QString::fromUtf8("special_word"));

        horizontalLayout_6->addWidget(special_word);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        new_password_label = new QLabel(forgot_password_form);
        new_password_label->setObjectName(QString::fromUtf8("new_password_label"));

        horizontalLayout_5->addWidget(new_password_label);

        new_password = new QLineEdit(forgot_password_form);
        new_password->setObjectName(QString::fromUtf8("new_password"));

        horizontalLayout_5->addWidget(new_password);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, 0, -1);
        confirm_new_password_label = new QLabel(forgot_password_form);
        confirm_new_password_label->setObjectName(QString::fromUtf8("confirm_new_password_label"));

        horizontalLayout_3->addWidget(confirm_new_password_label);

        confirm_new_password = new QLineEdit(forgot_password_form);
        confirm_new_password->setObjectName(QString::fromUtf8("confirm_new_password"));

        horizontalLayout_3->addWidget(confirm_new_password);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        change_password_button = new QPushButton(forgot_password_form);
        change_password_button->setObjectName(QString::fromUtf8("change_password_button"));
        change_password_button->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(change_password_button);

        back_to_login_button = new QPushButton(forgot_password_form);
        back_to_login_button->setObjectName(QString::fromUtf8("back_to_login_button"));
        back_to_login_button->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(back_to_login_button);


        horizontalLayout_2->addWidget(forgot_password_form);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        ForgottenPassword->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ForgottenPassword);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ForgottenPassword->setMenuBar(menubar);
        statusbar = new QStatusBar(ForgottenPassword);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ForgottenPassword->setStatusBar(statusbar);

        retranslateUi(ForgottenPassword);

        QMetaObject::connectSlotsByName(ForgottenPassword);
    } // setupUi

    void retranslateUi(QMainWindow *ForgottenPassword)
    {
        ForgottenPassword->setWindowTitle(QApplication::translate("ForgottenPassword", "MainWindow", nullptr));
        username_label->setText(QApplication::translate("ForgottenPassword", "Enter Username:", nullptr));
        special_word_label->setText(QApplication::translate("ForgottenPassword", "Enter Special Word", nullptr));
        new_password_label->setText(QApplication::translate("ForgottenPassword", "Enter New Password", nullptr));
        confirm_new_password_label->setText(QApplication::translate("ForgottenPassword", "Confirm New Password:", nullptr));
        change_password_button->setText(QApplication::translate("ForgottenPassword", "Change Password", nullptr));
        back_to_login_button->setText(QApplication::translate("ForgottenPassword", "Back to login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgottenPassword: public Ui_ForgottenPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTTENPASSWORD_H
