#include "Vehicle.h"

void Vehicle::draw(){
    /*
    fl_color(FL_BLACK);
    fl_rect(100, 100, 100, 100);
    fl_arc(100, 100, 15, 0, 360); //Arc fungerer ikke?
    fl_circle(100, 100, 15);
    fl_color(FL_BLUE);
    fl_pie(200, 100, 30, 30, 0, 360);
    */
    std::pair<double, double> pair = steer(); 
    state.update(pair.first, pair.second);
    if (state.x > screenWidth) state.x = screenWidth;
    if (state.x < 0) state.x = 0;
    if (state.y < 0) state.y = 0;
    if (state.y > screenHeight) state.y = screenHeight; 
    drawBody();
}

void PlayerVehicle::drawBody(){
    fl_color(FL_BLUE);
    fl_begin_polygon();
    fl_arc(state.x, state.y, vehicleRadius, 0, 330);
    fl_end_polygon();
    double snoutLength{vehicleRadius/2};
    fl_color(FL_MAGENTA);
    //fl_begin_polygon();
    //fl_line(state.x+vehicleRadius, state.y+vehicleRadius, state.x+vehicleRadius+snoutLength, state.y);
    //fl_line(state.x+vehicleRadius, state.y-vehicleRadius,state.x+vehicleRadius, state.y+vehicleRadius);
    //fl_line(state.x+vehicleRadius, state.y-vehicleRadius, state.x+vehicleRadius+snoutLength, state.y);
    /*
    double point1x{state.x+vehicleRadius};
    double point1y{state.y+vehicleRadius};
    double point2x{state.x+vehicleRadius+snoutLength};
    double point2y{state.y};
    double point3x{state.x+vehicleRadius};
    double point3y{state.y-vehicleRadius};
    double polVal1x{point1x*cos(state.angle)-point1y*sin(state.angle)};
    double polVal1y{point1x*sin(state.angle)+point1y*cos(state.angle)};
    fl_polygon(polVal1x*state.x+state.y*polVal1y,polVal1y,
               point2x*cos(state.angle)-point2y*sin(state.angle),point2x*sin(state.angle)+point2y*cos(state.angle), //Rotation 
               point3x*cos(state.angle)-point3y*sin(state.angle),point3x*sin(state.angle)+point3y*cos(state.angle)); //Should make a function here.
    */            
    //fl_end_polygon();
    //I want to change coordinates first, place origo in (state.x, state.y) and then use the rotational matrix!
    //Now it rotates around (0,0). I want it to rotate about (state.x, state.y)! Need to change the basis to this first!
    //Try more later!
    //also make the game fit for two-players!
}

std::pair<double, double> PlayerVehicle::steer() const {
    double translationAccelerationGas{0.7};
    double translationAccelerationTurn{-0.1};
    double translationAccelerationBrake{-0.9};
    double angularAcceleration{0.9};
    if (Fl::event_key(FL_Up)) return std::make_pair(translationAccelerationGas, 0);
    else if (Fl::event_key(FL_Left)) return std::make_pair(translationAccelerationTurn, -angularAcceleration);
    else if (Fl::event_key(FL_Right)) return std::make_pair(translationAccelerationTurn, angularAcceleration);
    else if (Fl::event_key(FL_Down)) return std::make_pair(translationAccelerationBrake, 0);
    else return std::make_pair(0,0); 
}

bool circleCollision(double delX, double delY, double sumR){
    //Maths
}
