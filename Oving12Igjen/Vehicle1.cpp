#include "Vehicle1.h"

Vehicle::Vehicle(double x, double y, double angle, const Track& track):Fl_Widget(10, 10, 10, 10), track{track}{
    state.x = x; 
    state.y = y;
    state.angle = angle;
    index = 0; 
    status = Obstacle::None;
    peelAngle = 0;
}

void Vehicle::draw(){
    collidedWithObstacle();
    std::pair<double, double> localVar = steer(); 
    if (status == Obstacle::Spill){
        state.grip = 0.5;
        state.update(localVar.second, localVar.first);
    } else if (status == Obstacle::Peel){
        if (state.speed > 2){
            state.slide(peelAngle);
        } if (state.speed < 0.3){
            status = Obstacle::None;
        }
    } else if (status == Obstacle::Boost){
        state.grip = 2;
        state.update(localVar.second, localVar.first);
    } else {
        state.update(localVar.second, localVar.first);
    }
    

    if (state.x > screenWidth-vehicleRadius) state.x = screenWidth-vehicleRadius;
    if (state.y > screenHeight-vehicleRadius) state.y = screenHeight-vehicleRadius;
    if (state.x < vehicleRadius) state.x = vehicleRadius;
    if (state.y < vehicleRadius) state.y = vehicleRadius;

    std::pair<double, double> current = track.getGoals()[index];
    if (circleCollision(state.x - current.first, state.y - current.second, vehicleRadius + goalRadius)){
        index = (index+1)%track.getGoals().size();
    }

    drawBody();
    
}

void PlayerVehicle::drawBody() const {
    
    fl_color(FL_RED);
    fl_begin_polygon();
    fl_pie(state.x-vehicleRadius, state.y-vehicleRadius, vehicleRadius*2, vehicleRadius*2, -(state.angle * 180 / 3.14 + 330), -(state.angle * 180 / 3.14 + 30));
    //fl_circle(state.x, state.y, vehicleRadius);
    fl_end_polygon();

    std::pair<double, double> current = track.getGoals()[index];
    fl_color(FL_YELLOW);    
    fl_begin_polygon();
    fl_circle(current.first, current.second, goalRadius);
    fl_end_polygon();
    
    
	
}

std::pair<double, double> PlayerVehicle::steer() const {
    double angleAcc = 0;
    double velAcc = 0;
    if (Fl::event_key(FL_Right)) return std::make_pair(angleAcc+1, velAcc);
    else if (Fl::event_key(FL_Left)) return std::make_pair(angleAcc-1, velAcc);
    else if (Fl::event_key(FL_Down)) return std::make_pair(angleAcc, velAcc-1);
    else if (Fl::event_key(FL_Up)) return std::make_pair(angleAcc, velAcc+1);
    return {angleAcc, velAcc};
}

void PlayerVehicle2::drawBody() const {
    
    fl_color(FL_BLUE);
    fl_begin_polygon();
    fl_pie(state.x-vehicleRadius, state.y-vehicleRadius, vehicleRadius*2, vehicleRadius*2, -(state.angle * 180 / 3.14 + 330), -(state.angle * 180 / 3.14 + 30));
    //fl_circle(state.x, state.y, vehicleRadius);
    fl_end_polygon();
    
	
}

std::pair<double, double> PlayerVehicle2::steer() const {
    double angleAcc = 0;
    double velAcc = 0;
    if (Fl::event_key('D')) return std::make_pair(angleAcc+1, velAcc);
    else if (Fl::event_key('A')) return std::make_pair(angleAcc-1, velAcc);
    else if (Fl::event_key('S')) return std::make_pair(angleAcc, velAcc-1);
    else if (Fl::event_key('W')) return std::make_pair(angleAcc, velAcc+1);
    return {angleAcc, velAcc};
}

bool circleCollision(double delX, double delY, double sumR){
    return ((pow(delX,2) + pow(delY,2)))<=pow(sumR,2);
}

void Vehicle::collidedWithObstacle(){
    for (auto obstacle : track.getObstacles()){
        if (std::get<2>(obstacle) == Obstacle::Boost){
            if (circleCollision(std::get<0>(obstacle)-state.x, std::get<1>(obstacle)-state.y, boostRadius + vehicleRadius)){
                status = Obstacle::Boost;
            }
        } else if (std::get<2>(obstacle) == Obstacle::Spill){
            if (circleCollision(std::get<0>(obstacle)-state.x, std::get<1>(obstacle)-state.y, spillRadius + vehicleRadius)){
                status = Obstacle::Spill;
            }

        } else if (std::get<2>(obstacle) == Obstacle::Peel){
            if (circleCollision(std::get<0>(obstacle)-state.x, std::get<1>(obstacle)-state.y, peelRadius + vehicleRadius)){
                status = Obstacle::Peel;
                peelAngle = state.angle;
            }
        } else{
            status = Obstacle::None;
        }
       
    }
    
}