#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <iomanip>

const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int year);
int daysInMonth(int m, int y);

struct Date {
    int d;
    int m; 
    int y; 
};

struct Event {
    std::string name;
    int id;
    Date when;
};

int dayNo(Date day);
Date stringToDate(std::string text);
bool checkDate(const Date& day);
std::string dateToString(const Date& day);

std::ostream& operator<<(std::ostream& out, const Event& rhs);
