#include <iostream>
#include <string>
#include <Point.h>
#include "Graph.h"
#include <sstream>
#include <map>

using namespace std;
using namespace Graph_lib;

//Example of given values.
constexpr int dispWidth = 500;
constexpr int dispHeight = 500;
constexpr int ridesPerDay = 1000;

struct Location{
    string name;
    Point p;
    Location(string str, Point p);
};

class BikeStation{
    Location loc;
    unsigned int capacity = 0;
    unsigned int bikes = 0;
    Vector_ref<Shape> display;
public: 
    unsigned int getBikes() const { return bikes; }
    void setBikes(unsigned int bike){ bikes = bike };
    string getName(){ return loc.name; }
    string status() const;
    BikeStation(Location where, unsigned int cap, unsigned int numBikes);
    unsigned int getCapacity() const { return capacity; }

};

map<string, int> simulateOneDay(vector<BikeStation*> bs);
void printStats(map<string, int> declined);
