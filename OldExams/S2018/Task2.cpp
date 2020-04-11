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
    //This was my first try, option 1. It partially works, but cannot check the size of year, month and day. 
    /*
    Date newDate;
    std::stringstream ss{text};
    int year(4);
    char line1;
    char line2;
    int month(2);
    int day(2);
    try{
        ss >> year >> line1 >> month >> line2 >> day;
        std::cout << year << " " << line1 << " " << month << " " << line2 << " " << day << std::endl;
        if (line1 != '-' || line2 != '-') throw std::invalid_argument("Wrong formatting of string "+text);
        else{
            newDate.d = day;
            newDate.y = year;
            newDate.m = month;
        }

    } catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return newDate;
    */
    //Attempt 2: Using substrings instead: 
    //This solution works entirely as it should!
    Date newDate;
    try{
        std::string year = text.substr(0,4);
        std::string month = text.substr(5,2);
        std::string day = text.substr(8,2);
        char line1 = text[4];
        char line2 = text[7];
        if (line1 != '-' || line2 != '-') throw std::invalid_argument("Wrong formatting of string "+text);
        if (text.size() != 10) throw "Invalid format";
        newDate.d = std::stoi(day);
        newDate.y = std::stoi(year);
        newDate.m = std::stoi(month);
    } catch(const std::exception& e){ //Unnecessary with all these catches. 
        std::cerr << e.what() << '\n';
    } catch(const std::invalid_argument& invA){
        std::cerr << invA.what() << '\n';
    } catch(...){
        std::cerr << "Invalid format" << std::endl;
    }
    return newDate;
}

bool checkDate(const Date& day){
    return ((day.m <= 12 && day.m >= 1) && (day.d <= daysInMonth(day.m, day.y) && day.d > 0));
}

std::string dateToString(const Date& day){
    
    if (!checkDate(day)) return "INVALID DATE";
    std::string year;
    std::string month = std::to_string(day.m);
    std::string dag = std::to_string(day.d);   
    while (year.size() != (4-year.size())) year += std::to_string(0);
    year += std::to_string(day.y);
    if (month.size() != 2) month = std::to_string(0);
    month += std::to_string(day.m);
    if (dag.size() != 2) dag = std::to_string(0);
    dag += std::to_string(day.d); 
    return year + '-' + month + '-' + dag;
    
    //LF solution with stringstream:
    /*
    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << day.y << '-' 
    << std::setw(2) << day.m << '-' << std::setw(2) << day.d;
    return ss.str();
    */
}

std::ostream& operator<<(std::ostream& out, const Event& rhs){
    
}  
