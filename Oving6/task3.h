#include "std_lib_facilities.h"

class CourseCatalog{
private:
    map<string, string> catalog;
public:
    CourseCatalog():catalog{}{}; //Like this?
    friend ostream& operator<<(ostream&, const CourseCatalog&);
    const string getCourse(string courseCode) const;
    void addCourse(const string courseCode, const string courseName);
    void removeCourse(const string courseCode);
    void readFromFile(const string filename);
    void writeToFile(const string filename);
};

class Course{ //used to make new readings. 
    string courseCode;
    string courseName;
public: 
    friend istream& operator>>(istream&, Course&);//Used when reading from file!
    string getCourseName() { return courseName ;};
    string getCourseCode() { return courseCode ;};
    
};
