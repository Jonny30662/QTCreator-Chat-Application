/********************************************************************************
** Form generated from reading UI file 'adminhome.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINHOME_H
#define UI_ADMINHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminHome
{
public:
    QWidget *central_widget;
    QVBoxLayout *verticalLayout;
    QWidget *TopWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *current_date_time;
    QSpacerItem *horizontalSpacer_7;
    QWidget *account_toppanel_button_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *account_name;
    QLabel *profile_pic;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *logoff_button;
    QPushButton *shutdown_button;
    QHBoxLayout *Page;
    QWidget *sidebar;
    QVBoxLayout *verticalLayout_6;
    QWidget *sidemenu_topbar_2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *home_button;
    QPushButton *manage_users_button;
    QPushButton *manage_groups_button;
    QPushButton *manage_mods_button;
    QPushButton *main_menu_button;
    QSpacerItem *verticalSpacer_5;
    QWidget *sidemen_bottom_2;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *InnerPage;
    QWidget *page_name_widget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *page_title_label;
    QSpacerItem *verticalSpacer_7;
    QWidget *page_contents_widget;
    QHBoxLayout *horizontalLayout_8;
    QTextBrowser *page_information;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminHome)
    {
        if (AdminHome->objectName().isEmpty())
            AdminHome->setObjectName(QString::fromUtf8("AdminHome"));
        AdminHome->resize(854, 716);
        central_widget = new QWidget(AdminHome);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        verticalLayout = new QVBoxLayout(central_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TopWidget = new QWidget(central_widget);
        TopWidget->setObjectName(QString::fromUtf8("TopWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setStyleSheet(QString::fromUtf8("#TopWidget { \n"
" background-color: DimGrey; \n"
" border-radius: 8px;\n"
"}\n"
"QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        horizontalLayout_9 = new QHBoxLayout(TopWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        current_date_time = new QLabel(TopWidget);
        current_date_time->setObjectName(QString::fromUtf8("current_date_time"));

        horizontalLayout_9->addWidget(current_date_time);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        account_toppanel_button_2 = new QWidget(TopWidget);
        account_toppanel_button_2->setObjectName(QString::fromUtf8("account_toppanel_button_2"));
        horizontalLayout_10 = new QHBoxLayout(account_toppanel_button_2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 1, -1, -1);
        account_name = new QLabel(account_toppanel_button_2);
        account_name->setObjectName(QString::fromUtf8("account_name"));

        horizontalLayout_10->addWidget(account_name);

        profile_pic = new QLabel(account_toppanel_button_2);
        profile_pic->setObjectName(QString::fromUtf8("profile_pic"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(profile_pic->sizePolicy().hasHeightForWidth());
        profile_pic->setSizePolicy(sizePolicy1);
        profile_pic->setMinimumSize(QSize(50, 50));
        profile_pic->setMaximumSize(QSize(50, 16777215));
        profile_pic->setStyleSheet(QString::fromUtf8("border: 1px solid;"));

        horizontalLayout_10->addWidget(profile_pic);


        horizontalLayout_9->addWidget(account_toppanel_button_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        logoff_button = new QPushButton(TopWidget);
        logoff_button->setObjectName(QString::fromUtf8("logoff_button"));
        sizePolicy1.setHeightForWidth(logoff_button->sizePolicy().hasHeightForWidth());
        logoff_button->setSizePolicy(sizePolicy1);
        logoff_button->setMinimumSize(QSize(60, 60));
        logoff_button->setStyleSheet(QString::fromUtf8("QPushButton { background-color: Gold; }\n"
"QPushButton:hover { background-color: DarkOrange; }"));

        horizontalLayout_9->addWidget(logoff_button);

        shutdown_button = new QPushButton(TopWidget);
        shutdown_button->setObjectName(QString::fromUtf8("shutdown_button"));
        sizePolicy1.setHeightForWidth(shutdown_button->sizePolicy().hasHeightForWidth());
        shutdown_button->setSizePolicy(sizePolicy1);
        shutdown_button->setMinimumSize(QSize(60, 60));
        shutdown_button->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #e11c2d; }\n"
"QPushButton:hover { background-color: #CE0000; }"));

        horizontalLayout_9->addWidget(shutdown_button);


        verticalLayout->addWidget(TopWidget);

        Page = new QHBoxLayout();
        Page->setObjectName(QString::fromUtf8("Page"));
        sidebar = new QWidget(central_widget);
        sidebar->setObjectName(QString::fromUtf8("sidebar"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy2);
        sidebar->setStyleSheet(QString::fromUtf8("#sidebar { \n"
" background-color: LightGrey;\n"
" border-radius: 8px;\n"
"}\n"
"QLabel { color: white; }\n"
"QPushButton {\n"
"    color: DimGrey;\n"
"    background-color: white;\n"
"    border-width: 0px;\n"
"    border-radius: 2px;\n"
"}\n"
"QPushButton:hover { \n"
"	background-color: DarkOrange;\n"
"	color: white;\n"
" \n"
"}"));
        verticalLayout_6 = new QVBoxLayout(sidebar);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, 1, 1);
        sidemenu_topbar_2 = new QWidget(sidebar);
        sidemenu_topbar_2->setObjectName(QString::fromUtf8("sidemenu_topbar_2"));
        verticalLayout_7 = new QVBoxLayout(sidemenu_topbar_2);
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(1, -1, -1, -1);
        home_button = new QPushButton(sidemenu_topbar_2);
        home_button->setObjectName(QString::fromUtf8("home_button"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(home_button->sizePolicy().hasHeightForWidth());
        home_button->setSizePolicy(sizePolicy3);
        home_button->setMinimumSize(QSize(130, 50));

        verticalLayout_7->addWidget(home_button);

        manage_users_button = new QPushButton(sidemenu_topbar_2);
        manage_users_button->setObjectName(QString::fromUtf8("manage_users_button"));
        manage_users_button->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(manage_users_button);

        manage_groups_button = new QPushButton(sidemenu_topbar_2);
        manage_groups_button->setObjectName(QString::fromUtf8("manage_groups_button"));
        manage_groups_button->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(manage_groups_button);

        manage_mods_button = new QPushButton(sidemenu_topbar_2);
        manage_mods_button->setObjectName(QString::fromUtf8("manage_mods_button"));
        manage_mods_button->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(manage_mods_button);

        main_menu_button = new QPushButton(sidemenu_topbar_2);
        main_menu_button->setObjectName(QString::fromUtf8("main_menu_button"));
        main_menu_button->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(main_menu_button);


        verticalLayout_6->addWidget(sidemenu_topbar_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        sidemen_bottom_2 = new QWidget(sidebar);
        sidemen_bottom_2->setObjectName(QString::fromUtf8("sidemen_bottom_2"));
        verticalLayout_8 = new QVBoxLayout(sidemen_bottom_2);
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        verticalLayout_6->addWidget(sidemen_bottom_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);


        Page->addWidget(sidebar);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_5);

        InnerPage = new QVBoxLayout();
        InnerPage->setObjectName(QString::fromUtf8("InnerPage"));
        InnerPage->setContentsMargins(0, -1, -1, -1);
        page_name_widget = new QWidget(central_widget);
        page_name_widget->setObjectName(QString::fromUtf8("page_name_widget"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(page_name_widget->sizePolicy().hasHeightForWidth());
        page_name_widget->setSizePolicy(sizePolicy4);
        page_name_widget->setMinimumSize(QSize(0, 100));
        page_name_widget->setStyleSheet(QString::fromUtf8("#page_name_widget { \n"
" background-color: white;\n"
" border-radius: 8px;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(page_name_widget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(1, -1, -1, -1);
        page_title_label = new QLabel(page_name_widget);
        page_title_label->setObjectName(QString::fromUtf8("page_title_label"));
        page_title_label->setMinimumSize(QSize(0, 0));
        page_title_label->setStyleSheet(QString::fromUtf8("#page_title_label  {\n"
"	color: DimGrey;\n"
"	font-size: 50px;\n"
"}"));
        page_title_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(page_title_label);


        InnerPage->addWidget(page_name_widget);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        InnerPage->addItem(verticalSpacer_7);

        page_contents_widget = new QWidget(central_widget);
        page_contents_widget->setObjectName(QString::fromUtf8("page_contents_widget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(page_contents_widget->sizePolicy().hasHeightForWidth());
        page_contents_widget->setSizePolicy(sizePolicy5);
        page_contents_widget->setStyleSheet(QString::fromUtf8("#page_contents_widget { \n"
" background-color: white;\n"
" border-radius: 8px;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(page_contents_widget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        page_information = new QTextBrowser(page_contents_widget);
        page_information->setObjectName(QString::fromUtf8("page_information"));

        horizontalLayout_8->addWidget(page_information);


        InnerPage->addWidget(page_contents_widget);


        Page->addLayout(InnerPage);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(Page);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        AdminHome->setCentralWidget(central_widget);
        menubar = new QMenuBar(AdminHome);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 854, 22));
        AdminHome->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminHome);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminHome->setStatusBar(statusbar);

        retranslateUi(AdminHome);

        QMetaObject::connectSlotsByName(AdminHome);
    } // setupUi

    void retranslateUi(QMainWindow *AdminHome)
    {
        AdminHome->setWindowTitle(QApplication::translate("AdminHome", "MainWindow", nullptr));
        current_date_time->setText(QApplication::translate("AdminHome", "Date/Time", nullptr));
        account_name->setText(QApplication::translate("AdminHome", "Account", nullptr));
        profile_pic->setText(QApplication::translate("AdminHome", "profilepic", nullptr));
        logoff_button->setText(QString());
        shutdown_button->setText(QString());
        home_button->setText(QApplication::translate("AdminHome", "Admin Home", nullptr));
        manage_users_button->setText(QApplication::translate("AdminHome", "Manage Users", nullptr));
        manage_groups_button->setText(QApplication::translate("AdminHome", "Manage Groups", nullptr));
        manage_mods_button->setText(QApplication::translate("AdminHome", "Manage Mods", nullptr));
        main_menu_button->setText(QApplication::translate("AdminHome", "Main Menu", nullptr));
        page_title_label->setText(QApplication::translate("AdminHome", "Admin", nullptr));
        page_information->setHtml(QApplication::translate("AdminHome", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The admin section allows you to view all users, groups and moderators and allows you to do a whole number of things such as remove users, groups, moderators and whole number of other things.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">How To Use The Admin Features:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0p"
                        "x; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Manage users :</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This page displays all users of the application. You first need to select any user in the table. You will see the user row glows orange. After this the buttons at the bottom of the page will become avaliable. You can either reset password which will become 'password' (this will be encrypted) or, you can delete the user account.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br "
                        "/></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Manage Groups:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This page displays all listed groups. The rows are based on individual users. You can see from the group ID column which user belongs to which group. </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Selecting a user will make the row glow orange and the buttons at the bottom of the page will become avaliable. The admin or someone with a moderat"
                        "or status can access this page and either remove a group or remove a user from a certain group.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Manage Mods:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This page displays the users that have moderator privileges for the whole application, not for individual groups. From this page you can promote or demote mods. Mods have access to all the application admin features, however, they are unable to demote the admin or themselves.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminHome: public Ui_AdminHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOME_H
