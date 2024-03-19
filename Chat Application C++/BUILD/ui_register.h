/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topPanel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *current_date_time;
    QSpacerItem *horizontalSpacer;
    QPushButton *shutdown_button;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *RegisterForm;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Username_label;
    QLineEdit *username_input;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Password_label;
    QLineEdit *password_input;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Confirm_password_label;
    QLineEdit *confirm_password_input;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *FirstName_label;
    QLineEdit *first_name_input;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LastName_label;
    QLineEdit *last_name_input;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Email_label;
    QLineEdit *email_input;
    QHBoxLayout *horizontalLayout;
    QLabel *Special_Word_label;
    QLineEdit *special_word_input;
    QSpacerItem *verticalSpacer_4;
    QPushButton *register_button;
    QPushButton *back_to_login;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(800, 618);
        Register->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topPanel = new QWidget(Register);
        topPanel->setObjectName(QString::fromUtf8("topPanel"));
        topPanel->setStyleSheet(QString::fromUtf8("#topPanel { \n"
" background-color: DimGrey; \n"
" border-radius: 8px;\n"
"}\n"
"QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }\n"
""));
        horizontalLayout_4 = new QHBoxLayout(topPanel);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        current_date_time = new QLabel(topPanel);
        current_date_time->setObjectName(QString::fromUtf8("current_date_time"));

        horizontalLayout_4->addWidget(current_date_time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

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

        horizontalLayout_4->addWidget(shutdown_button);


        verticalLayout->addWidget(topPanel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        RegisterForm = new QWidget(Register);
        RegisterForm->setObjectName(QString::fromUtf8("RegisterForm"));
        sizePolicy.setHeightForWidth(RegisterForm->sizePolicy().hasHeightForWidth());
        RegisterForm->setSizePolicy(sizePolicy);
        RegisterForm->setMinimumSize(QSize(400, 500));
        RegisterForm->setCursor(QCursor(Qt::ArrowCursor));
        RegisterForm->setStyleSheet(QString::fromUtf8("#RegisterForm { \n"
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
"}\n"
" "));
        verticalLayout_2 = new QVBoxLayout(RegisterForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(35, 35, 35, 35);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Username_label = new QLabel(RegisterForm);
        Username_label->setObjectName(QString::fromUtf8("Username_label"));
        Username_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_6->addWidget(Username_label);

        username_input = new QLineEdit(RegisterForm);
        username_input->setObjectName(QString::fromUtf8("username_input"));
        username_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_6->addWidget(username_input);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Password_label = new QLabel(RegisterForm);
        Password_label->setObjectName(QString::fromUtf8("Password_label"));
        Password_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_7->addWidget(Password_label);

        password_input = new QLineEdit(RegisterForm);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        password_input->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(password_input);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        Confirm_password_label = new QLabel(RegisterForm);
        Confirm_password_label->setObjectName(QString::fromUtf8("Confirm_password_label"));
        Confirm_password_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));
        Confirm_password_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Confirm_password_label->setWordWrap(false);
        Confirm_password_label->setMargin(0);

        horizontalLayout_8->addWidget(Confirm_password_label);

        confirm_password_input = new QLineEdit(RegisterForm);
        confirm_password_input->setObjectName(QString::fromUtf8("confirm_password_input"));
        confirm_password_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        confirm_password_input->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(confirm_password_input);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        FirstName_label = new QLabel(RegisterForm);
        FirstName_label->setObjectName(QString::fromUtf8("FirstName_label"));
        FirstName_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_9->addWidget(FirstName_label);

        first_name_input = new QLineEdit(RegisterForm);
        first_name_input->setObjectName(QString::fromUtf8("first_name_input"));
        first_name_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_9->addWidget(first_name_input);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LastName_label = new QLabel(RegisterForm);
        LastName_label->setObjectName(QString::fromUtf8("LastName_label"));
        LastName_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_10->addWidget(LastName_label);

        last_name_input = new QLineEdit(RegisterForm);
        last_name_input->setObjectName(QString::fromUtf8("last_name_input"));
        last_name_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_10->addWidget(last_name_input);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        Email_label = new QLabel(RegisterForm);
        Email_label->setObjectName(QString::fromUtf8("Email_label"));
        Email_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_11->addWidget(Email_label);

        email_input = new QLineEdit(RegisterForm);
        email_input->setObjectName(QString::fromUtf8("email_input"));
        email_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout_11->addWidget(email_input);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Special_Word_label = new QLabel(RegisterForm);
        Special_Word_label->setObjectName(QString::fromUtf8("Special_Word_label"));
        Special_Word_label->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit { border-radius: 3px; }"));

        horizontalLayout->addWidget(Special_Word_label);

        special_word_input = new QLineEdit(RegisterForm);
        special_word_input->setObjectName(QString::fromUtf8("special_word_input"));
        special_word_input->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(special_word_input);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        register_button = new QPushButton(RegisterForm);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setMinimumSize(QSize(0, 40));
        register_button->setCursor(QCursor(Qt::PointingHandCursor));
        register_button->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(register_button);

        back_to_login = new QPushButton(RegisterForm);
        back_to_login->setObjectName(QString::fromUtf8("back_to_login"));
        back_to_login->setMinimumSize(QSize(0, 40));
        back_to_login->setCursor(QCursor(Qt::PointingHandCursor));
        back_to_login->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(back_to_login);


        horizontalLayout_5->addWidget(RegisterForm);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", nullptr));
        current_date_time->setText(QString());
        shutdown_button->setText(QString());
        Username_label->setText(QApplication::translate("Register", "Username:", nullptr));
        Password_label->setText(QApplication::translate("Register", "Password:", nullptr));
        password_input->setText(QString());
        Confirm_password_label->setText(QApplication::translate("Register", "Confirm Password:", nullptr));
        FirstName_label->setText(QApplication::translate("Register", "First Name:", nullptr));
        LastName_label->setText(QApplication::translate("Register", "Last Name:", nullptr));
        Email_label->setText(QApplication::translate("Register", "Email:", nullptr));
        Special_Word_label->setText(QApplication::translate("Register", "Special Word:", nullptr));
        register_button->setText(QApplication::translate("Register", "Register", nullptr));
        back_to_login->setText(QApplication::translate("Register", "Back to login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
