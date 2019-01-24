#ifndef MWTIME
#define MWTIME
 
typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
 
void initTime(Time *time)
{
    time->hour = 0;
    time->minute = 0;
    time->second = 0;
}
void setTime(Time *time, int hour, int minute, int second)
{
    time->hour = hour;
    time->minute = minute;
    time->second = second;
}
void addTime(Time *time, int hour, int minute, int second)
{
    time->second += second + minute * 60 + hour * 3600;
    time->minute += time->second / 60;
    time->hour += time->minute / 60;
    time->second %= 60;
    time->minute %= 60;
    time->hour %= 24;
}
void printTime(Time *time)
{
#ifdef H24
    printf("%.2d:%.2d:%.2d\n", time->hour, time->minute, time->second);
    return;
#endif
    printf("%.2d%s:%.2d:%.2d\n", time->hour > 12 ? time->hour - 12 : (time->hour == 0 ? 12 : time->hour), time->hour >= 12 ? "pm" : "am", time->minute, time->second);
}
#endif