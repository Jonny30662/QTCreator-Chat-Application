/********************************************************************************
** Form generated from reading UI file 'adminmanagemods.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMANAGEMODS_H
#define UI_ADMINMANAGEMODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminManageMods
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
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QWidget *button_widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *promote_button;
    QPushButton *demote_button;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminManageMods)
    {
        if (AdminManageMods->objectName().isEmpty())
            AdminManageMods->setObjectName(QString::fromUtf8("AdminManageMods"));
        AdminManageMods->resize(1390, 1086);
        central_widget = new QWidget(AdminManageMods);
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        tableWidget = new QTableWidget(page_contents_widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(1100, 330));
        tableWidget->setMaximumSize(QSize(1100, 16777215));
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        tableWidget->setTabletTracking(false);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"background-color: #C0C0C0;\n"
"alternate-background-color: DimGrey;\n"
"selection-background-color: DarkOrange;\n"
"color: white;\n"
"}\n"
""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setSortingEnabled(true);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableWidget);

        label = new QLabel(page_contents_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 150));

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        button_widget = new QWidget(page_contents_widget);
        button_widget->setObjectName(QString::fromUtf8("button_widget"));
        button_widget->setCursor(QCursor(Qt::PointingHandCursor));
        button_widget->setStyleSheet(QString::fromUtf8("#button_widget{\n"
"background-color: LightGrey;\n"
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
        verticalLayout_3 = new QVBoxLayout(button_widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 20, 20, 20);
        promote_button = new QPushButton(button_widget);
        promote_button->setObjectName(QString::fromUtf8("promote_button"));
        promote_button->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(promote_button);

        demote_button = new QPushButton(button_widget);
        demote_button->setObjectName(QString::fromUtf8("demote_button"));
        demote_button->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(demote_button);


        verticalLayout_2->addWidget(button_widget);


        horizontalLayout_8->addLayout(verticalLayout_2);


        InnerPage->addWidget(page_contents_widget);


        Page->addLayout(InnerPage);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Page->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(Page);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        AdminManageMods->setCentralWidget(central_widget);
        menubar = new QMenuBar(AdminManageMods);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1390, 22));
        AdminManageMods->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminManageMods);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminManageMods->setStatusBar(statusbar);

        retranslateUi(AdminManageMods);

        QMetaObject::connectSlotsByName(AdminManageMods);
    } // setupUi

    void retranslateUi(QMainWindow *AdminManageMods)
    {
        AdminManageMods->setWindowTitle(QApplication::translate("AdminManageMods", "MainWindow", nullptr));
        current_date_time->setText(QApplication::translate("AdminManageMods", "Date/Time", nullptr));
        account_name->setText(QApplication::translate("AdminManageMods", "Account", nullptr));
        profile_pic->setText(QApplication::translate("AdminManageMods", "profilepic", nullptr));
        logoff_button->setText(QString());
        shutdown_button->setText(QString());
        home_button->setText(QApplication::translate("AdminManageMods", "Home", nullptr));
        manage_users_button->setText(QApplication::translate("AdminManageMods", "Manage Users", nullptr));
        manage_groups_button->setText(QApplication::translate("AdminManageMods", "Manage Groups", nullptr));
        manage_mods_button->setText(QApplication::translate("AdminManageMods", "Manage Mods", nullptr));
        main_menu_button->setText(QApplication::translate("AdminManageMods", "Main Menu", nullptr));
        page_title_label->setText(QApplication::translate("AdminManageMods", "Manage Mods", nullptr));
        label->setText(QString());
        promote_button->setText(QApplication::translate("AdminManageMods", "Promote User", nullptr));
        demote_button->setText(QApplication::translate("AdminManageMods", "Demote Mod", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminManageMods: public Ui_AdminManageMods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMANAGEMODS_H
