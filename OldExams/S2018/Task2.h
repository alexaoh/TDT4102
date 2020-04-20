#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

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
void printEvents(std::vector<Event*>& events);

class Calendar{
    std::string name;
    std::map<int, Event*> events;
public: 
    Calendar(std::string name):name{name}{}
    ~Calendar();
    void addEvent(int id, std::string name, int year, int month, int day);
    std::vector<Event*> getEvents(int year, int month, int day);
    std::vector<Date> busyDates(int threshold);
};
