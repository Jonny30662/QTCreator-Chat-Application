/********************************************************************************
** Form generated from reading UI file 'messagingpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGINGPAGE_H
#define UI_MESSAGINGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagingPageNew
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
    QWidget *page_contents_widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *recipient_name;
    QSpacerItem *horizontalSpacer_3;
    QLabel *active_status;
    QSpacerItem *verticalSpacer_7;
    QWidget *page_contents_widget_2;
    QHBoxLayout *horizontalLayout_8;
    QGridLayout *gridLayout;
    QPushButton *group_button;
    QSpacerItem *verticalSpacer_2;
    QTextBrowser *display_messages;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *write_message;
    QPushButton *send_button;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MessagingPageNew)
    {
        if (MessagingPageNew->objectName().isEmpty())
            MessagingPageNew->setObjectName(QString::fromUtf8("MessagingPageNew"));
        MessagingPageNew->resize(1145, 782);
        central_widget = new QWidget(MessagingPageNew);
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
        profile_pic->setMaximumSize(QSize(50, 16777215));
        profile_pic->setStyleSheet(QString::fromUtf8("border: 1px solid;"));

        horizontalLayout_10->addWidget(profile_pic);


        horizontalLayout_9->addWidget(account_toppanel_button_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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
        page_contents_widget = new QWidget(central_widget);
        page_contents_widget->setObjectName(QString::fromUtf8("page_contents_widget"));
        page_contents_widget->setMaximumSize(QSize(16777215, 100));
        page_contents_widget->setStyleSheet(QString::fromUtf8("#page_contents_widget { \n"
" background-color: white;\n"
" border-radius: 8px;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(page_contents_widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        recipient_name = new QLabel(page_contents_widget);
        recipient_name->setObjectName(QString::fromUtf8("recipient_name"));
        recipient_name->setMinimumSize(QSize(0, 0));
        recipient_name->setMaximumSize(QSize(16777215, 80));
        recipient_name->setStyleSheet(QString::fromUtf8("#page_title_label_2{\n"
"	color: DimGrey;\n"
"	font-size: 50px;\n"
"}"));
        recipient_name->setTextFormat(Qt::PlainText);
        recipient_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        recipient_name->setMargin(20);

        horizontalLayout_5->addWidget(recipient_name);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        active_status = new QLabel(page_contents_widget);
        active_status->setObjectName(QString::fromUtf8("active_status"));
        active_status->setLayoutDirection(Qt::LeftToRight);
        active_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(active_status);


        InnerPage->addWidget(page_contents_widget);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        InnerPage->addItem(verticalSpacer_7);

        page_contents_widget_2 = new QWidget(central_widget);
        page_contents_widget_2->setObjectName(QString::fromUtf8("page_contents_widget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(page_contents_widget_2->sizePolicy().hasHeightForWidth());
        page_contents_widget_2->setSizePolicy(sizePolicy4);
        page_contents_widget_2->setStyleSheet(QString::fromUtf8("#page_contents_widget_2 { \n"
" background-color: white;\n"
" border-radius: 8px;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(page_contents_widget_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        group_button = new QPushButton(page_contents_widget_2);
        group_button->setObjectName(QString::fromUtf8("group_button"));
        group_button->setMaximumSize(QSize(60, 40));
        group_button->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(group_button, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        display_messages = new QTextBrowser(page_contents_widget_2);
        display_messages->setObjectName(QString::fromUtf8("display_messages"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(display_messages->sizePolicy().hasHeightForWidth());
        display_messages->setSizePolicy(sizePolicy5);
        display_messages->setMinimumSize(QSize(550, 0));
        display_messages->setMaximumSize(QSize(550, 16777215));
        display_messages->setStyleSheet(QString::fromUtf8(""));
        display_messages->setFrameShape(QFrame::StyledPanel);
        display_messages->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(display_messages, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        write_message = new QTextEdit(page_contents_widget_2);
        write_message->setObjectName(QString::fromUtf8("write_message"));
        write_message->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(write_message, 3, 1, 1, 1);

        send_button = new QPushButton(page_contents_widget_2);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        send_button->setMaximumSize(QSize(60, 40));

        gridLayout->addWidget(send_button, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);


        horizontalLayout_8->addLayout(gridLayout);


        InnerPage->addWidget(page_contents_widget_2);


        Page->addLayout(InnerPage);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(Page);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        MessagingPageNew->setCentralWidget(central_widget);
        menubar = new QMenuBar(MessagingPageNew);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1145, 22));
        MessagingPageNew->setMenuBar(menubar);
        statusbar = new QStatusBar(MessagingPageNew);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MessagingPageNew->setStatusBar(statusbar);

        retranslateUi(MessagingPageNew);

        QMetaObject::connectSlotsByName(MessagingPageNew);
    } // setupUi

    void retranslateUi(QMainWindow *MessagingPageNew)
    {
        MessagingPageNew->setWindowTitle(QApplication::translate("MessagingPageNew", "MainWindow", nullptr));
        current_date_time->setText(QApplication::translate("MessagingPageNew", "Date/Time", nullptr));
        account_name->setText(QApplication::translate("MessagingPageNew", "Account", nullptr));
        profile_pic->setText(QApplication::translate("MessagingPageNew", "profilepic", nullptr));
        logoff_button->setText(QString());
        shutdown_button->setText(QString());
        home_button->setText(QApplication::translate("MessagingPageNew", "Home", nullptr));
        chats_button->setText(QApplication::translate("MessagingPageNew", "Chats", nullptr));
        groups_button->setText(QApplication::translate("MessagingPageNew", "Groups", nullptr));
        accounts_button->setText(QApplication::translate("MessagingPageNew", "Accounts", nullptr));
        settings_button->setText(QApplication::translate("MessagingPageNew", "Settings", nullptr));
        manage_users_button->setText(QApplication::translate("MessagingPageNew", "Manage Users", nullptr));
        manage_groups_button->setText(QApplication::translate("MessagingPageNew", "Manage Groups", nullptr));
        manage_mods_button->setText(QApplication::translate("MessagingPageNew", "Manage Mods", nullptr));
        recipient_name->setText(QApplication::translate("MessagingPageNew", "Test_Group", nullptr));
        active_status->setText(QApplication::translate("MessagingPageNew", "Active Status", nullptr));
        group_button->setText(QApplication::translate("MessagingPageNew", "Manage", nullptr));
        send_button->setText(QApplication::translate("MessagingPageNew", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagingPageNew: public Ui_MessagingPageNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGINGPAGE_H
