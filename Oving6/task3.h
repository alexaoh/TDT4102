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
