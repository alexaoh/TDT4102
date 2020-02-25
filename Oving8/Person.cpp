#include "std_lib_facilities.h"
#include "Person.h"

bool Person::hasAvailableSeats() const{
    return car->hasFreeSeats();
    //tror dette skal funke, men har ikke testa!
    //--> fungerer fint når personen har en bil!
}

ostream& operator<<(ostream& os, const Person& p){
    os << "Name: " << p.name << ", " << p.email << ". \n" 
       << "Has room in own car: " << boolalpha << p.hasAvailableSeats() << ".";
    return os;
}
