#include "std_lib_facilities.h"
#include "Car.h"
#include "Person.h"

int main()
{
    //Tests for Person: 
    Person john{"John", "john@johnson.com"};
    Car cenasCar{2};
    Car* cenasCarPtr = &cenasCar;

    Person cena{"Cena", "cena@cenation.ucantCMe.com", cenasCarPtr};
    cenasCar.reserveFreeSeat();

   // cout << john << endl; --> this one gives memory error (since it has no car). 
   //-->need to read about nullptr to fix this probably!
    cout << cena;


}
