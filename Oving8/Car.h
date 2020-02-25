#pragma once
#include "std_lib_facilities.h"

class Car{
    int freeSeats;

public:
    Car(int freeSeats):freeSeats{freeSeats}{};
    bool hasFreeSeats() const;
    void reserveFreeSeat();

};
