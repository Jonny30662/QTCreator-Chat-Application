/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

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

class Ui_Settings
{
public:
    QWidget *central_widget;
    QVBoxLayout *verticalLayout;
    QWidget *TopWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *current_date_time;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *accessibility_button;
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
    QPushButton *chats_button;
    QPushButton *groups_button;
    QPushButton *accounts_button;
    QPushButton *settings_button;
    QSpacerItem *verticalSpacer_5;
    QWidget *sidemen_bottom_2;
    QVBoxLayout *verticalLayout_8;
    QPushButton *manage_users_button;
    QPushButton *manage_groups_button;
    QPushButton *manage_mods_button;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *InnerPage;
    QWidget *page_name_widget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *page_title_label;
    QSpacerItem *verticalSpacer_7;
    QWidget *page_contents_widget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_10;
    QWidget *setting_left_widget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *username_label;
    QLineEdit *new_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password_label;
    QLineEdit *new_password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *new_first_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *new_last_name;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *new_email;
    QHBoxLayout *horizontalLayout_6;
    QLabel *special_word_label;
    QLineEdit *new_special_word;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *update_details_button;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *browse_button;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(1032, 816);
        central_widget = new QWidget(Settings);
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

        accessibility_button = new QPushButton(TopWidget);
        accessibility_button->setObjectName(QString::fromUtf8("accessibility_button"));
        accessibility_button->setMinimumSize(QSize(100, 25));
        accessibility_button->setStyleSheet(QString::fromUtf8("#accessibility_button { \n"
" background-color: white; \n"
" border-radius: 8px;\n"
"color: black;\n"
"}\n"
"#accessibility_button:hover { \n"
"	background-color: black;\n"
"	color: white;\n"
"}\n"
""));

        horizontalLayout_9->addWidget(accessibility_button);

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
        profile_pic->setMaximumSize(QSize(50, 16777215));
        profile_pic->setStyleSheet(QString::fromUtf8("border: 1px solid;"));

        horizontalLayout_10->addWidget(profile_pic);


        horizontalLayout_9->addWidget(account_toppanel_button_2);

        horizontalSpacer_8 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        logoff_button = new QPushButton(TopWidget);
        logoff_button->setObjectName(QString::fromUtf8("logoff_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logoff_button->sizePolicy().hasHeightForWidth());
        logoff_button->setSizePolicy(sizePolicy1);
        logoff_button->setMinimumSize(QSize(60, 60));
        logoff_button->setCursor(QCursor(Qt::PointingHandCursor));
        logoff_button->setStyleSheet(QString::fromUtf8("QPushButton { background-color: Gold; }\n"
"QPushButton:hover { background-color: DarkOrange; }"));

        horizontalLayout_9->addWidget(logoff_button);

        shutdown_button = new QPushButton(TopWidget);
        shutdown_button->setObjectName(QString::fromUtf8("shutdown_button"));
        sizePolicy1.setHeightForWidth(shutdown_button->sizePolicy().hasHeightForWidth());
        shutdown_button->setSizePolicy(sizePolicy1);
        shutdown_button->setMinimumSize(QSize(60, 60));
        shutdown_button->setCursor(QCursor(Qt::PointingHandCursor));
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
        sidemenu_topbar_2->setCursor(QCursor(Qt::PointingHandCursor));
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

        chats_button = new QPushButton(sidemenu_topbar_2);
        chats_button->setObjectName(QString::fromUtf8("chats_button"));
        chats_button->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(chats_button);

        groups_button = new QPushButton(sidemenu_topbar_2);
        groups_button->setObjectName(QString::fromUtf8("groups_button"));
        groups_button->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(groups_button);

        accounts_button = new QPushButton(sidemenu_topbar_2);
        accounts_button->setObjectName(QString::fromUtf8("accounts_button"));
        accounts_button->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(accounts_button);

        settings_button = new QPushButton(sidemenu_topbar_2);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));
        settings_button->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(settings_button);


        verticalLayout_6->addWidget(sidemenu_topbar_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        sidemen_bottom_2 = new QWidget(sidebar);
        sidemen_bottom_2->setObjectName(QString::fromUtf8("sidemen_bottom_2"));
        sidemen_bottom_2->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout_8 = new QVBoxLayout(sidemen_bottom_2);
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        manage_users_button = new QPushButton(sidemen_bottom_2);
        manage_users_button->setObjectName(QString::fromUtf8("manage_users_button"));
        manage_users_button->setMinimumSize(QSize(60, 60));

        verticalLayout_8->addWidget(manage_users_button);

        manage_groups_button = new QPushButton(sidemen_bottom_2);
        manage_groups_button->setObjectName(QString::fromUtf8("manage_groups_button"));
        manage_groups_button->setMinimumSize(QSize(60, 60));

        verticalLayout_8->addWidget(manage_groups_button);

        manage_mods_button = new QPushButton(sidemen_bottom_2);
        manage_mods_button->setObjectName(QString::fromUtf8("manage_mods_button"));
        manage_mods_button->setMinimumSize(QSize(60, 60));

        verticalLayout_8->addWidget(manage_mods_button);


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
        page_title_label->setStyleSheet(QString::fromUtf8("#page_title_label {\n"
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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        setting_left_widget = new QWidget(page_contents_widget);
        setting_left_widget->setObjectName(QString::fromUtf8("setting_left_widget"));
        setting_left_widget->setStyleSheet(QString::fromUtf8("\n"
"#setting_left_widget{\n"
"background-color: white;\n"
"border-radius: 8px;\n"
"}\n"
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
"}"));
        verticalLayout_3 = new QVBoxLayout(setting_left_widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(35, 35, 35, 35);
        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 0, -1, -1);
        username_label = new QLabel(setting_left_widget);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(username_label);

        new_username = new QLineEdit(setting_left_widget);
        new_username->setObjectName(QString::fromUtf8("new_username"));
        sizePolicy1.setHeightForWidth(new_username->sizePolicy().hasHeightForWidth());
        new_username->setSizePolicy(sizePolicy1);
        new_username->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_13->addWidget(new_username);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        password_label = new QLabel(setting_left_widget);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(password_label->sizePolicy().hasHeightForWidth());
        password_label->setSizePolicy(sizePolicy6);
        password_label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(password_label);

        new_password = new QLineEdit(setting_left_widget);
        new_password->setObjectName(QString::fromUtf8("new_password"));
        sizePolicy1.setHeightForWidth(new_password->sizePolicy().hasHeightForWidth());
        new_password->setSizePolicy(sizePolicy1);
        new_password->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(new_password);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(setting_left_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_2);

        new_first_name = new QLineEdit(setting_left_widget);
        new_first_name->setObjectName(QString::fromUtf8("new_first_name"));
        sizePolicy1.setHeightForWidth(new_first_name->sizePolicy().hasHeightForWidth());
        new_first_name->setSizePolicy(sizePolicy1);
        new_first_name->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(new_first_name);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(setting_left_widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_3);

        new_last_name = new QLineEdit(setting_left_widget);
        new_last_name->setObjectName(QString::fromUtf8("new_last_name"));
        sizePolicy1.setHeightForWidth(new_last_name->sizePolicy().hasHeightForWidth());
        new_last_name->setSizePolicy(sizePolicy1);
        new_last_name->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(new_last_name);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(setting_left_widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_4);

        new_email = new QLineEdit(setting_left_widget);
        new_email->setObjectName(QString::fromUtf8("new_email"));
        sizePolicy1.setHeightForWidth(new_email->sizePolicy().hasHeightForWidth());
        new_email->setSizePolicy(sizePolicy1);
        new_email->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(new_email);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        special_word_label = new QLabel(setting_left_widget);
        special_word_label->setObjectName(QString::fromUtf8("special_word_label"));
        special_word_label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(special_word_label);

        new_special_word = new QLineEdit(setting_left_widget);
        new_special_word->setObjectName(QString::fromUtf8("new_special_word"));
        sizePolicy1.setHeightForWidth(new_special_word->sizePolicy().hasHeightForWidth());
        new_special_word->setSizePolicy(sizePolicy1);
        new_special_word->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(new_special_word);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        update_details_button = new QPushButton(setting_left_widget);
        update_details_button->setObjectName(QString::fromUtf8("update_details_button"));
        update_details_button->setMinimumSize(QSize(0, 40));
        update_details_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_11->addWidget(update_details_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        browse_button = new QPushButton(setting_left_widget);
        browse_button->setObjectName(QString::fromUtf8("browse_button"));
        sizePolicy.setHeightForWidth(browse_button->sizePolicy().hasHeightForWidth());
        browse_button->setSizePolicy(sizePolicy);
        browse_button->setMinimumSize(QSize(200, 40));
        browse_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(browse_button);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_12);


        horizontalLayout->addWidget(setting_left_widget);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);


        horizontalLayout_8->addLayout(horizontalLayout);


        InnerPage->addWidget(page_contents_widget);


        Page->addLayout(InnerPage);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(Page);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        Settings->setCentralWidget(central_widget);
        menubar = new QMenuBar(Settings);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1032, 22));
        Settings->setMenuBar(menubar);
        statusbar = new QStatusBar(Settings);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Settings->setStatusBar(statusbar);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QMainWindow *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "MainWindow", nullptr));
        current_date_time->setText(QApplication::translate("Settings", "Date/Time", nullptr));
        accessibility_button->setText(QApplication::translate("Settings", "Dark Mode", nullptr));
        account_name->setText(QApplication::translate("Settings", "Account", nullptr));
        profile_pic->setText(QApplication::translate("Settings", "profilepic", nullptr));
        logoff_button->setText(QString());
        shutdown_button->setText(QString());
        home_button->setText(QApplication::translate("Settings", "Home", nullptr));
        chats_button->setText(QApplication::translate("Settings", "Chats", nullptr));
        groups_button->setText(QApplication::translate("Settings", "Groups", nullptr));
        accounts_button->setText(QApplication::translate("Settings", "Accounts", nullptr));
        settings_button->setText(QApplication::translate("Settings", "Settings", nullptr));
        manage_users_button->setText(QApplication::translate("Settings", "Manage Users", nullptr));
        manage_groups_button->setText(QApplication::translate("Settings", "Manage Groups", nullptr));
        manage_mods_button->setText(QApplication::translate("Settings", "Manage Mods", nullptr));
        page_title_label->setText(QApplication::translate("Settings", "Settings", nullptr));
        username_label->setText(QApplication::translate("Settings", "Username:", nullptr));
        password_label->setText(QApplication::translate("Settings", "Password:", nullptr));
        label_2->setText(QApplication::translate("Settings", "FirstName:", nullptr));
        label_3->setText(QApplication::translate("Settings", "LastName:", nullptr));
        label_4->setText(QApplication::translate("Settings", "Email:", nullptr));
        special_word_label->setText(QApplication::translate("Settings", "Special Word:", nullptr));
        update_details_button->setText(QApplication::translate("Settings", "Update Details", nullptr));
        browse_button->setText(QApplication::translate("Settings", "Change Profile Picture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
