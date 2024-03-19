#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <QString>
#include <QImage>

QT_BEGIN_NAMESPACE
class global_variables;
QT_END_NAMESPACE

extern QString current_user;
extern QString current_recipient;
extern QString current_account_type;
extern QString topic;
extern QImage image;
extern QImage account_image;
extern bool account_checked;
extern bool group_manager;
extern QString dark_mode_toggle;
extern int inactive_minutes;
extern int inactive_seconds;
extern QTimer *inactivity_timer;


#endif // GLOBAL_VARIABLES_H
