#include "std_lib_facilities.h"
#include "task5.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
using namespace Graph_lib;
//usikker på hvilke av disse header-filene som faktisk brukes?!

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
Scale ys{ymax-yoffset, base_temp, -yscale};

void buildGraph(){
    Window win{Point{100, 100}, xmax, ymax, "Daglige maks- og minimumstemperaturer fra 3.februar 2018 til og med 3.februar 2019"};

    const int months{12};
    Axis x{Axis::x, Point{xoffset, (ymax-yoffset)/2}, xlength, months, 
    "            Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct   Nov   Dec   Jan   "};
    x.label.move(-100, 0);

    Axis y{Axis::y, Point{xoffset, ymax-yoffset}, ylength, 5, "degrees (Centigrade)"};

    /* Unødvendig
    Line current_temp{Point{xs(6), ys(0)}, Point{xs(6), ys(100)}}; //Wrong numbers here. 
    current_temp.set_style(Line_style::dash);
    */

    Open_polyline max_temps; 
    Open_polyline min_temps; 
    
    vector<Temps> temps = readAllTempsFromFile("temperatures.txt");
    int x_placement = 0;
    for (auto i : temps){
        const int x = xs(x_placement);
        const int max_y = ys(i.getMax());
        const int min_y = ys(i.getMin());

        max_temps.add(Point{x, max_y});
        min_temps.add(Point{x, min_y});

        x_placement++;
    }

    max_temps.set_color(Color::red);
    min_temps.set_color(Color::blue);

    Text Max{Point{xoffset/2, ymax/2}, "Max"};
    Max.set_color(Color::red);

    Text Min{Point{xoffset/2, ymax/2+20}, "Min"};
    Min.set_color(Color::blue);

    //Need 5 more texts for values on y-axis!

    //attach axes
    win.attach(x);
    win.attach(y);
    
    //attach polylines
    win.attach(max_temps);
    win.attach(min_temps);

    //attach texts
    win.attach(Max);
    win.attach(Min);


    gui_main();
}
