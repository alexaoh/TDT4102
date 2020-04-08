#include "Task2.h"

bool isLeapYear(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int m, int y){
    if (m == 2 && isLeapYear(y)) return months[1] + 1;
    return months[m-1];
}

int dayNo(Date day){
    int days{0};
    for (int i = 1; i < day.m; ++i){
        days += daysInMonth(i, day.y);
    }
    return (days + day.d);
}

Date stringToDate(std::string text){
    std::stringstream ss{text};
    int year(4);
    char line1;
    char line2;
    int month(2);
    int day(2);
    ss >> year >> line1 >> month >> line2 >> day;
    
}
