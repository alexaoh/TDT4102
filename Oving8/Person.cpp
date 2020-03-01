#include "std_lib_facilities.h"
#include "Person.h"

bool Person::hasAvailableSeats() const{
    try{
        if (car==nullptr) throw runtime_error("null pointer argument to car.");
        return car->hasFreeSeats();
    }
    catch (...){
        cout << "(since the person does not have a car) ";
        return false;
    }
    
    
}

ostream& operator<<(ostream& os, const Person& p){
    os << "Name: " << p.name << ", Email: " << p.email << ". \n" 
       << " Has room in own car: " << boolalpha << p.hasAvailableSeats() << ".";
    return os;
}
