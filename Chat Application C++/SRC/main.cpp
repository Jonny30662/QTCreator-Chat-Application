#include "mainwindow.h"
#include "messagingpage.h"
#include "homepage.h"
#include "settings.h"
#include "groups.h"
#include "accounts.h"
#include "adminhome.h"
#include "adminmanageusers.h"
#include "project_database.h"
#include "groupchats.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MessagingPageNew m;
    HomePageNewest hn;
    Settings s;
    Groups g;
    Accounts ac;
    AdminHome ah;
    AdminManageUsers amu;
    GroupChats gc;

    w.show();
    return a.exec();
}
