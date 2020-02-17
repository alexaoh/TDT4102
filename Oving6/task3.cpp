#include "std_lib_facilities.h"
#include "task3.h"

const string CourseCatalog::getCourse(string courseCode) const{
    string courseName = catalog.at(courseCode); //.at() is best to use when finding element in map, since it throws exception of not there. 
    return courseName;
}

void CourseCatalog::addCourse(const string courseCode, const string courseName){
    catalog[courseCode] = courseName; // -->Overwrites 
    //catalog.insert(pair<string, string>(courseCode,courseName));
    // --> insert() does not overwrite. 
    return;
}

void CourseCatalog::removeCourse(const string courseCode){
    catalog.erase(courseCode);
    return;
}

ostream& operator<<(ostream& os, const CourseCatalog& catalog){
    os << "All the courses are: " << endl;
    for (const auto cat : catalog.catalog){
        os << "Coursecode " << cat.first 
           << "|Coursename " << cat.second 
           << endl;             
    }
    return os; 
}

void CourseCatalog::readFromFile(const string filename){
    ifstream ist{filename};
    if (!ist) error("Can't open input file, ", filename);
    
    for (Course c; ist>>c; ){
        if (ist.fail()){ //Denne fungerer ikke, fordi den failer i betingelsen og går aldri inn i løkka!
                        //Hvordan kunne jeg "fått tak i failen"? (den svslutter bare løkka når den failer!)
            error ("ikke |");
        }
        catalog[c.getCourseCode()] = c.getCourseName();
    }
    return; 

}

void CourseCatalog::writeToFile(const string filename){
    ofstream ost{filename};
    if (!ost) error("Can't open output file, ", filename);
    for (const auto cat : catalog){
        ost << cat.first << " | " << cat.second << endl; 
    }
    return;


}

istream& operator>>(istream& is, Course& c){
    //Reads a new key-value pair into c
    //Assume format: CourseCode|Coursename
    // --> Does not work if \t in Coursename. Fix?

    char ch1;
    string c1;
    string c2;
    is >> c1 >> ch1 >> c2;
    if (!is) return is;
    if (ch1!='|'){
        is.clear(ios_base::failbit);
        return is;
    }
    c.courseCode = c1;
    c.courseName = c2;
    return is;

}
