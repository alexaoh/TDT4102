#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <iostream>
#include <tuple>
#include "utilities.h"
#include <FL/Fl.H>
#include "Track.h"

class Vehicle : public Fl_Widget{
protected:
    virtual std::pair<double, double> steer() const = 0;
    virtual void drawBody() const = 0; 
    PhysicsState state;
    const Track& track;
    int index;
    Obstacle status; //If collided with obstacle or not. 
    double peelAngle; //Saves angle when hitting peel. 
public:
    Vehicle(double x, double y, double angle, const Track& track);
    void draw() final;
    void collidedWithObstacle();

};

class PlayerVehicle : public Vehicle{ 
protected:
    void drawBody() const override;
    std::pair<double, double> steer() const override;
public: 
    PlayerVehicle(double x, double y, double angle, const Track& track):Vehicle(x, y, angle, track){}

};

class PlayerVehicle2 : public Vehicle{ 
protected:
    void drawBody() const override;
    std::pair<double, double> steer() const override;
public: 
    PlayerVehicle2(double x, double y, double angle, const Track& track):Vehicle(x, y, angle, track){}
};

bool circleCollision(double delX, double delY, double sumR);
