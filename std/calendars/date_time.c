#include "date_time.h"

void get_current_local_date_time(date_time* dt) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    dt -> year = tm -> tm_year + 1900;
    dt -> month = tm -> tm_mon;
    dt -> day = tm -> tm_mday;
    dt -> hour = tm -> tm_hour;
    dt -> minute = tm -> tm_min;
    dt -> second = tm -> tm_sec;
}
