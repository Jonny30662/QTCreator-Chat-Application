/********************************************************************************
** Form generated from reading UI file 'adminsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSETTINGS_H
#define UI_ADMINSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminSettings
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *TopWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *currentDateTime_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *account_toppanel_button_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *account_name_2;
    QLabel *profile_pic;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *logoff_button_2;
    QPushButton *shutdown_button_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Page;
    QWidget *sidebar_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *sidemenu_topbar_2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *home_button_2;
    QPushButton *musers_button_2;
    QPushButton *mgroups_button_2;
    QPushButton *mmods_button_2;
    QPushButton *settings_button_2;
    QSpacerItem *verticalSpacer_5;
    QWidget *sidemen_bottom_2;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *InnerPage;
    QWidget *PageName_widget_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *page_title_label_2;
    QSpacerItem *verticalSpacer_7;
    QWidget *Pagecontents_widget_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminSettings)
    {
        if (AdminSettings->objectName().isEmpty())
            AdminSettings->setObjectName(QString::fromUtf8("AdminSettings"));
        AdminSettings->resize(800, 600);
        centralwidget = new QWidget(AdminSettings);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        TopWidget = new QWidget(centralwidget);
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
        currentDateTime_2 = new QLabel(TopWidget);
        currentDateTime_2->setObjectName(QString::fromUtf8("currentDateTime_2"));

        horizontalLayout_9->addWidget(currentDateTime_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        account_toppanel_button_2 = new QWidget(TopWidget);
        account_toppanel_button_2->setObjectName(QString::fromUtf8("account_toppanel_button_2"));
        horizontalLayout_10 = new QHBoxLayout(account_toppanel_button_2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 1, -1, -1);
        account_name_2 = new QLabel(account_toppanel_button_2);
        account_name_2->setObjectName(QString::fromUtf8("account_name_2"));

        horizontalLayout_10->addWidget(account_name_2);

        profile_pic = new QLabel(account_toppanel_button_2);
        profile_pic->setObjectName(QString::fromUtf8("profile_pic"));
        profile_pic->setStyleSheet(QString::fromUtf8("border: 1px solid;"));

        horizontalLayout_10->addWidget(profile_pic);


        horizontalLayout_9->addWidget(account_toppanel_button_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        logoff_button_2 = new QPushButton(TopWidget);
        logoff_button_2->setObjectName(QString::fromUtf8("logoff_button_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logoff_button_2->sizePolicy().hasHeightForWidth());
        logoff_button_2->setSizePolicy(sizePolicy1);
        logoff_button_2->setMinimumSize(QSize(60, 60));
        logoff_button_2->setStyleSheet(QString::fromUtf8("QPushButton { background-color: Gold; }\n"
"QPushButton:hover { background-color: DarkOrange; }"));

        horizontalLayout_9->addWidget(logoff_button_2);

        shutdown_button_2 = new QPushButton(TopWidget);
        shutdown_button_2->setObjectName(QString::fromUtf8("shutdown_button_2"));
        sizePolicy1.setHeightForWidth(shutdown_button_2->sizePolicy().hasHeightForWidth());
        shutdown_button_2->setSizePolicy(sizePolicy1);
        shutdown_button_2->setMinimumSize(QSize(60, 60));
        shutdown_button_2->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #e11c2d; }\n"
"QPushButton:hover { background-color: #CE0000; }"));

        horizontalLayout_9->addWidget(shutdown_button_2);


        verticalLayout_2->addWidget(TopWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Page = new QHBoxLayout();
        Page->setObjectName(QString::fromUtf8("Page"));
        sidebar_2 = new QWidget(centralwidget);
        sidebar_2->setObjectName(QString::fromUtf8("sidebar_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sidebar_2->sizePolicy().hasHeightForWidth());
        sidebar_2->setSizePolicy(sizePolicy2);
        sidebar_2->setStyleSheet(QString::fromUtf8("#sidebar_2 { \n"
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
        verticalLayout_6 = new QVBoxLayout(sidebar_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, 1, 1);
        sidemenu_topbar_2 = new QWidget(sidebar_2);
        sidemenu_topbar_2->setObjectName(QString::fromUtf8("sidemenu_topbar_2"));
        verticalLayout_7 = new QVBoxLayout(sidemenu_topbar_2);
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(1, -1, -1, -1);
        home_button_2 = new QPushButton(sidemenu_topbar_2);
        home_button_2->setObjectName(QString::fromUtf8("home_button_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(home_button_2->sizePolicy().hasHeightForWidth());
        home_button_2->setSizePolicy(sizePolicy3);
        home_button_2->setMinimumSize(QSize(130, 50));

        verticalLayout_7->addWidget(home_button_2);

        musers_button_2 = new QPushButton(sidemenu_topbar_2);
        musers_button_2->setObjectName(QString::fromUtf8("musers_button_2"));
        musers_button_2->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(musers_button_2);

        mgroups_button_2 = new QPushButton(sidemenu_topbar_2);
        mgroups_button_2->setObjectName(QString::fromUtf8("mgroups_button_2"));
        mgroups_button_2->setMinimumSize(QSize(50, 50));

        verticalLayout_7->addWidget(mgroups_button_2);

        mmods_button_2 = new QPushButton(sidemenu_topbar_2);
        mmods_button_2->setObjectName(QString::fromUtf8("mmods_button_2"));
        mmods_button_2->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(mmods_button_2);

        settings_button_2 = new QPushButton(sidemenu_topbar_2);
        settings_button_2->setObjectName(QString::fromUtf8("settings_button_2"));
        settings_button_2->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(settings_button_2);


        verticalLayout_6->addWidget(sidemenu_topbar_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        sidemen_bottom_2 = new QWidget(sidebar_2);
        sidemen_bottom_2->setObjectName(QString::fromUtf8("sidemen_bottom_2"));
        verticalLayout_8 = new QVBoxLayout(sidemen_bottom_2);
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        verticalLayout_6->addWidget(sidemen_bottom_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);


        Page->addWidget(sidebar_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_5);

        InnerPage = new QVBoxLayout();
        InnerPage->setObjectName(QString::fromUtf8("InnerPage"));
        InnerPage->setContentsMargins(0, -1, -1, -1);
        PageName_widget_2 = new QWidget(centralwidget);
        PageName_widget_2->setObjectName(QString::fromUtf8("PageName_widget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(PageName_widget_2->sizePolicy().hasHeightForWidth());
        PageName_widget_2->setSizePolicy(sizePolicy4);
        PageName_widget_2->setMinimumSize(QSize(0, 100));
        PageName_widget_2->setStyleSheet(QString::fromUtf8("#PageName_widget_2 { \n"
" background-color: white;\n"
" border-radius: 8px;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(PageName_widget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(1, -1, -1, -1);
        page_title_label_2 = new QLabel(PageName_widget_2);
        page_title_label_2->setObjectName(QString::fromUtf8("page_title_label_2"));
        page_title_label_2->setMinimumSize(QSize(0, 0));
        page_title_label_2->setStyleSheet(QString::fromUtf8("#page_title_label_2{\n"
"	color: DimGrey;\n"
"	font-size: 50px;\n"
"}"));
        page_title_label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(page_title_label_2);


        InnerPage->addWidget(PageName_widget_2);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        InnerPage->addItem(verticalSpacer_7);

        Pagecontents_widget_2 = new QWidget(centralwidget);
        Pagecontents_widget_2->setObjectName(QString::fromUtf8("Pagecontents_widget_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Pagecontents_widget_2->sizePolicy().hasHeightForWidth());
        Pagecontents_widget_2->setSizePolicy(sizePolicy5);
        Pagecontents_widget_2->setStyleSheet(QString::fromUtf8("#Pagecontents_widget_2 { \n"
" background-color: white;\n"
" border-radius: 8px;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(Pagecontents_widget_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        InnerPage->addWidget(Pagecontents_widget_2);


        Page->addLayout(InnerPage);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(Page);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        AdminSettings->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminSettings);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        AdminSettings->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminSettings);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminSettings->setStatusBar(statusbar);

        retranslateUi(AdminSettings);

        QMetaObject::connectSlotsByName(AdminSettings);
    } // setupUi

    void retranslateUi(QMainWindow *AdminSettings)
    {
        AdminSettings->setWindowTitle(QApplication::translate("AdminSettings", "MainWindow", nullptr));
        currentDateTime_2->setText(QApplication::translate("AdminSettings", "Date/Time", nullptr));
        account_name_2->setText(QApplication::translate("AdminSettings", "Account", nullptr));
        profile_pic->setText(QApplication::translate("AdminSettings", "profilepic", nullptr));
        logoff_button_2->setText(QString());
        shutdown_button_2->setText(QString());
        home_button_2->setText(QApplication::translate("AdminSettings", "Home", nullptr));
        musers_button_2->setText(QApplication::translate("AdminSettings", "Manage Users", nullptr));
        mgroups_button_2->setText(QApplication::translate("AdminSettings", "Manage Groups", nullptr));
        mmods_button_2->setText(QApplication::translate("AdminSettings", "Manage Mods", nullptr));
        settings_button_2->setText(QApplication::translate("AdminSettings", "Settings", nullptr));
        page_title_label_2->setText(QApplication::translate("AdminSettings", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSettings: public Ui_AdminSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSETTINGS_H
