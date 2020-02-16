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

//Får ikke denne til å virke som jeg ønsker!?
void CourseCatalog::readFromFile(const string filename){
    ifstream ist{filename};
    if (!ist) error("Can't open input file, ", filename);
    string first; 
    string second;
    string temp;
    for (char in; ist >> in; ){
        if (in == '|'){
            catalog[first] = "temp";
            temp = first;
            first = "";
        } else if (in == '\n'){
            catalog[temp] = first; 
            first = "";
        } else{
            first.push_back(in);
        }
    }
    return; 

}

void CourseCatalog::writeToFile(const string filename){
    ofstream ost{filename};
    if (!ost) error("Can't open output file, ", filename);
    for (const auto cat : catalog){
        ost << cat.first << "|" << cat.second << endl; 
    }
    return;


}
