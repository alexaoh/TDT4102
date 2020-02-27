#include "std_lib_facilities.h"
#include "Car.h"
#pragma once

class Person{
    string name;
    string email;
    Car* car;
public: 
    Person(string noim, string mailAddress, Car* carro = nullptr):name{noim}, email{mailAddress}, car{carro}{};
    string getName() const { return name; };
    string getEmail() const { return email; };
    void setEmail(string mailAddress){ email = mailAddress; };
    bool hasAvailableSeats() const;
    friend ostream& operator<<(ostream& os, const Person& p); //Person bør være const her, fordi operatoren ikke skal endre på objektet den kalles på. 
};
