#pragma once
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl.H>


constexpr int screenWidth = 1000;
constexpr int screenHeight = 600;

constexpr double vehicleRadius = 15;

constexpr double goalRadius = 30;

constexpr double spillRadius = 20;
constexpr double boostRadius = 10;
constexpr double peelRadius = 5;


class PhysicsState{
public:
	double x, y, angle, speed = 0, grip = 1;
	void update(double translationAcceleration, double angularAcceleration);
	void slide(double slideAngle);
};

double angleBetween(std::pair<double, double> vec1,std::pair<double, double> vec2);


class Vehicle : public Fl_Widget{
protected: 
	PhysicsState state; 
	Vehicle(double x, double y, double angle):Fl_Widget{10, 10, 10, 10}{ //Den ville ikke initialisere med en Initializer list (?) Sjekk LF for dette. 
		state.x = x;
		state.y = y;
		state.angle = angle;
	};
	virtual std::pair<double, double> steer() const = 0;
	virtual void drawBody() = 0;
public: 
	virtual void draw() final; //Hvorfor ikke void draw() override, sånn som i Track-klassen? 
};

class PlayerVehicle : public Vehicle{
public: 
	PlayerVehicle(double x, double y, double angle):Vehicle{x, y, angle}{};
	void drawBody() override;
	std::pair<double, double> steer() const override;
};

class Track : public Fl_Widget{
	std::vector<std::pair<double, double>> goals;
public: 
	Track();
	void draw() override;
};

bool circleCollision(double delX, double delY, double sumR); //Avgjør om to sirkler overlapper. 
