#include "global_variables.hpp"

QString current_user = "username";
QString current_recipient = "recipient";
QString current_account_type = "User";
QImage image;
QImage account_image;
QTimer *inactivity_timer;
bool account_checked = false;
bool group_manager = false;
QString dark_mode_toggle = "Light";
int inactive_minutes = 0;
int inactive_seconds = 0;

