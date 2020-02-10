#include "std_lib_facilities.h"
#include "task3.h"

CourseCatalog::CourseCatalog(){
    //construct nem catalog.
}

const string CourseCatalog::getCourse(string courseCode) const{
    string courseName = catalog[courseCode]; //use find() or something instead!? Check Forelesning uke 6!
    return courseName;
}

void CourseCatalog::addCourse(){
    //add a course to the catalog
}

void CourseCatalog::removeCourse(){
    //remove a course from the catalog
}

friend ostream& operator<<(ostream&, const CourseCatalog&){
    //operator-overlasting av << 
}
