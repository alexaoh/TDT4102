#include "std_lib_facilities.h"
#include "Car.h"
#include "Person.h"
#include "Meeting.h"

int main()
{
   
    //Tests for Person: 
    Person john{"John", "john@johnson.com"};
    Car cenasCar{3};
    Car* cenasCarPtr = &cenasCar;

    Person cena{"Cena", "cena@cenation.ucantCMe.com", cenasCarPtr};
    cenasCar.reserveFreeSeat();

    cout << john << endl; 
    cout << cena << endl;
    
    /*
    Jeg måtte legge inn en sjekk for nullptr, se Person::hasAvailableSeats().
    */

    //Meetings:
    cout << endl; 
    Meeting møte1{13, 10, 12, Campus::Trondheim, "Corona", &john};
    møte1.addParticipant(&cena);
    Meeting møte2{13, 11, 13, Campus::Trondheim, "Fotball",  &cena};

    cout << endl;
    cout << "Has room to another meeting: " << endl;
    for (auto x :  møte2.findPotentialCoDriving()){
        cout << *x;
    }
    cout << endl;



}
