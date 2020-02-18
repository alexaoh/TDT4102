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
           << "|Coursename" << cat.second 
           << endl;             
    }
    return os; 
}

void CourseCatalog::readFromFile(const string filename){
    ifstream ist{filename};
    if (!ist) error("Can't open input file, ", filename);
    
    

    //Solution 1: 
    while(true){
        if (ist.eof()){
            break;
        }

        if (ist.fail()){
            error("Ikke | som delimiter");
        }
        Course c; 
        ist >> c;
        catalog[c.getCourseCode()] = c.getCourseName();
    }
    /*
    for (Course c; ist>>c; ){
        if (ist.fail()){ //Denne fungerer ikke, fordi den failer i betingelsen og går aldri inn i løkka!
                        //Hvordan kunne jeg "fått tak i failen"? (den svslutter bare løkka når den failer!)
                        //Kunne kjørt en while, også sjekket betingelsen før ist>>c!
            error ("ikke |");
        }
        
        
    }
    return; 
    */
    

    /*
    //Solution 2: 
    //Prøver heller å lese inn en og en linje, uten a bruke >>:
    string line;
    while (getline(ist, line)){
        
        stringstream ss{line};
        string courseCode; 
        string courseName;
        string delimiter; 
        ss >> courseCode >> delimiter;
        getline(ss, courseName);
        catalog[courseCode] = courseName;

    }
    return;
    */
    
    

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

    char delimiter;
    string courseCode;
    string courseName;
    //stringstream ss(is);
    is >> courseCode >> delimiter;
    getline(is, courseName);

    if (!is) return is;
    if (delimiter!='|'){
        is.clear(ios_base::failbit);
        return is;
    }
    c.courseCode = courseCode;
    c.courseName = courseName;
    
    return is;
    

}
