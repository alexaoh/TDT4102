#include "std_lib_facilities.h"
#include "task4.h"

istream& operator>>(istream& is, Temps& t){
    double d1{0.0};
    double d2{0.0};
    
    is >> d1 >> d2;

    t.max = d1;
    t.min = d2;
    return is;
}

/* //Moved to main because of compiling errors. 
vector<Temps> readAllTempsFromFile(string filename){
    vector<Temps> temps;
    ifstream ist{filename};
    string in;
    while (true){
        if (ist.eof()) break;
        Temps t; 
        ist >> t;
        temps.push_back(t);
    }
    return temps;
}
*/

ostream& operator<<(ostream& os, const Temps& t){
    os << "Max temp: " << t.max << "|" << "Min temp: " << t.min; 
    return os;
}
