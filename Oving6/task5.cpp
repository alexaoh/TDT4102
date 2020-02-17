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


Scale xs{xoffset, 0, xscale};
Scale ys{(ymax-yoffset)/2, 0, -yscale};

void buildGraph(){
    Window win{Point{100, 100}, xmax, ymax, "Daglige maks- og minimumstemperaturer fra 3.februar 2018 til og med 3.februar 2019"};

    Axis x{Axis::x, Point{xoffset, (ymax-yoffset)/2}, xlength, months, 
    " Feb        Mar        Apr       May       Jun        Jul        Aug        Sep        Oct         Nov        Dec        Jan   "};
    x.label.move(-150, 0);

    Axis y{Axis::y, Point{xoffset, ymax-yoffset}, ylength, 0, "degrees (Centigrade)"};

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

    Text Max{Point{xoffset/2, max_temps.point(10).y}, "Max"};
    Max.set_color(Color::red);

    Text Min{Point{xoffset/2, min_temps.point(10).y}, "Min"};
    Min.set_color(Color::blue);

    const double movePoints{-20.0};
    Text minusTwenty{Point{xs(0), ys(-20)}, "-20"};
    minusTwenty.move(movePoints, 0);
    Text minusTen{Point{xs(0), ys(-10)}, "-10"};
    minusTen.move(movePoints, 0);
    Text zero{Point{xs(0), ys(0)}, "0"};
    zero.move(movePoints,0);
    Text Ten{Point{xs(0), ys(10)}, "10"};
    Ten.move(movePoints, 0);
    Text Twenty{Point{xs(0), ys(20)}, "20"};
    Twenty.move(movePoints, 0);


    //attach axes
    win.attach(x);
    win.attach(y);
    
    //attach polylines
    win.attach(max_temps);
    win.attach(min_temps);

    //attach texts
    win.attach(Max);
    win.attach(Min);

    //attach points
    win.attach(minusTwenty);
    win.attach(minusTen);
    win.attach(zero);
    win.attach(Ten);
    win.attach(Twenty);


    gui_main();
}
