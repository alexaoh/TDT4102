#include <iostream>
#include <fstream>
#include <sstream>

const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int year);
int daysInMonth(int m, int y);

struct Date {
    int d;
    int m; 
    int y; 
};

int dayNo(Date day);
Date stringToDate(std::string text);
