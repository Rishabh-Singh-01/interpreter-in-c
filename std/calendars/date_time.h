#ifndef STD_CALENDARS_DATE_TIME
#define STD_CALENDARS_DATE_TIME

#include <time.h>

typedef struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} date_time;

void get_current_local_date_time(date_time* dt);

#endif
