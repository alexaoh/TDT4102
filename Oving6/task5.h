#include "task4.h"
#include "std_lib_facilities.h"

constexpr int xmax = 950;
constexpr int ymax = 650;

constexpr int xoffset = 100;
constexpr int yoffset = 60;

constexpr int xspace = 40;
constexpr int yspace = 40;

//Length of axes 
constexpr int xlength = xmax-xoffset-xspace; //365 days in the year
constexpr int ylength = ymax-yoffset-yspace;

const int months{12};

vector<Temps> readAllTempsFromFile(string filename);
const int findMinTemp(vector<Temps>& readTemps);
const int findMaxTemp(vector<Temps>& readTemps);

/* Tried to find max and min of the entire map, but get loads of errors. Define som other consts for now. 
vector<Temps> readings;
readings = readAllTempsFromFile("temperatures.txt");
const int base_temp = findMinTemp(readings);
const int end_temp = findMaxTemp(readings);

cout << "Max temp: " << to_string(end_temp) << "| Min temp: " << to_string(base_temp) << endl;
*/

//guess some values --> Ville egt finne max og min
const int base_temp = -40;
const int end_temp = 40;

constexpr double xscale = double(xlength)/365;
constexpr double yscale = double(ylength)/(end_temp-base_temp);

class Scale{
    int cbase; 
    int vbase;
    double scale;
public: 
    Scale(int b, int vb, double s):cbase{b}, vbase{vb}, scale{s}{}
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

void buildGraph();

