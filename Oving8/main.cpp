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
    


}
