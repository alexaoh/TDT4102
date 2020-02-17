#include "std_lib_facilities.h"
#include "task5.h"
#include "Graph.h"
using namespace Graph_lib;

//er noe rart i denne fila her!!
vector<Temps> readAllTempsFromFile(string filename){
    vector<Temps> temps;
    ifstream ist{filename};
    string in;
    while (true){
        if (ist.eof()) break;
        Temps t; 
        ist >> t;
        temps.push_back(t);
    }
    return temps;
}

const int findMinTemp(vector<Temps>& readTemps){
    double min{0.0};
    double temp{0.0};
    for (auto x : readTemps){
        temp = x.getMin();
        if (temp <= min){
            min = temp;
        }
    }
    const double minima = min;
    return minima;
}

const int findMaxTemp(vector<Temps>& readTemps){
    double max{0.0};
    double temp{0.0};
    for (auto x : readTemps){
        temp = x.getMax();
        if (temp >= max){
            max = temp;
        }
    }
    const double maxima = max;
    return maxima;
}


Scale xs{xoffset, base_temp, xscale};
Scale ys{ymax-yoffset, 0, -yscale};

Window win {Point{100, 100}, xmax, ymax, "Daglige maks- og minimumstemperaturer fra 3.februar 2018 til og med 3.februar 2019"};

Axis x{Axis::x, Point{xoffset, ymax-yoffset}, xlength, (end_temp-base_temp)/10, 
"Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec  Jan  "}; 
x.label.mve(-100, 0);

Axis y{Axis::y, Point{xoffset, ymax-yoffset}, ylength, 10, "degrees (Centigrade)"};

Line current_temp{Point{xs(2008), ys(0)}, Point{xs(2008), ys(100)}} //Wrong numbers here. 
current_temp.set_style(Line_style::dash);
