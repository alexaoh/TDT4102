#pragma once
#include "utilities.h"

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

bool circleCollision(double delX, double delY, double sumR); //Avgjør om to sirkler overlapper. 
