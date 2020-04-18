#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <map>

struct Obs {
    int x; 
    int y;
};

std::vector<Obs> readObservations();
bool operator<(Obs& lhs, Obs& rhs);
void report(std::vector<Obs> vec, int threshold);
