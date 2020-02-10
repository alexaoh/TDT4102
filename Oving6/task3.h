#include "std_lib_facilities.h"

class CourseCatalog{
private:
    map<string, string> catalog;
    void addCourse();
    void removeCourse();

public:
    CourseCatalog();
    friend ostream& operator<<(ostream&, const CourseCatalog&);
    const string getCourse(string courseCode) const;
};
