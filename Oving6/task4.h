#include "std_lib_facilities.h"

class Temps{
    double max{0.0};
    double min{0.0};
public: 
    friend istream& operator>>(istream& is, Temps& t);
    friend ostream& operator<<(ostream& os, Temps& t); //used to print the vectors for testing in main. 
    double getMin() const { return min; }; 
    double getMax() const { return max; };
};
