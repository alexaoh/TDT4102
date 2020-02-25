#include "std_lib_facilities.h"
#include "Car.h"

bool Car::hasFreeSeats() const {
    return freeSeats>0 ? true : false;
}

void Car::reserveFreeSeat(){
    freeSeats--;
    return;
}

