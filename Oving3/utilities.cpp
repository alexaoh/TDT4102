#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithLimits(int lowerLimit, int upperLimit){
    //Skjønner ikke helt hvordan man setter upper og lower limit
    //Hvorfor fungerer dette med moduloen?
    int random_number = rand() % (upperLimit-lowerLimit) + lowerLimit;

    return random_number;
}
