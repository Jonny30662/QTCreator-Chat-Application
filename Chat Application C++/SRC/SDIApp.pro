QT       += core gui network mqtt sql quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accounts.cpp \
    adminhome.cpp \
    adminmanagegroups.cpp \
    adminmanagemods.cpp \
    adminmanageusers.cpp \
    existingchats.cpp \
    forgottenpassword.cpp \
    global_variables.cpp \
    groupchats.cpp \
    groups.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    messagingpage.cpp \
    register.cpp \
    settings.cpp

HEADERS += \
    accounts.h \
    adminhome.h \
    adminmanagegroups.h \
    adminmanagemods.h \
    adminmanageusers.h \
    existingchats.h \
    forgottenpassword.h \
    global_variables.hpp \
    groupchats.h \
    groups.h \
    homepage.h \
    mainwindow.h \
    messagingpage.h \
    project_database.h \
    register.h \
    settings.h

FORMS += \
    accounts.ui \
    adminhome.ui \
    adminmanagegroups.ui \
    adminmanagemods.ui \
    adminmanageusers.ui \
    existingchats.ui \
    forgottenpassword.ui \
    groupchats.ui \
    groups.ui \
    homepage.ui \
    mainwindow.ui \
    messagingpage.ui \
    register.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../../Downloads/user-solid.svg \
    a30662.txt \
    default_user.jpg \
    jw.txt \
    logoff.png \
    shutdown.png
