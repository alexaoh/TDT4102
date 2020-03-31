#include "Track.h"
#include <iostream>

Track::Track():Fl_Widget{10, 10, 10, 10}{
    //Make random track and push to goals-vector!
    //Could draw a lemniscate as a track for example!
    int amountOfCheckpoints{30};
    int increment{screenHeight/20};
    for (int i = 0; i<amountOfCheckpoints; ++i){
        std::pair<double, double> newPair = std::make_pair(i*increment, i*increment);
        goals.push_back(newPair);
    }
}

void Track::draw(){
    //for point in goals: Draw arc
    int counter{0};
    for (std::vector<std::pair<double, double>>::iterator it = goals.begin(); it != goals.end(); ++it){
        counter++;
        std::cout << counter << "\n";
        //std::cout << "first: " << it->first << " Second: " << it->second << "\n";
        fl_color(FL_BLACK);
        fl_arc(it->first, it->second, goalRadius, 0, 360);
        //fl_arc does not draw anything!?!?!
    }

}
