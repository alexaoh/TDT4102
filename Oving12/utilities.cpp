#include "utilities.h"

void PhysicsState::slide(double slideAngle){
    grip += 0.01 * (1 - grip);
    speed -= 0.036 * grip * speed;

    angle += 0.12 * grip;
    x += speed * cos(slideAngle);
    y += speed * sin(slideAngle);
}

void PhysicsState::update(double translationAcceleration, double angularAcceleration){
    // Desse skal vere i intervallet [-1,1]
    translationAcceleration = std::max(-1.0, std::min(1.0, translationAcceleration));
    angularAcceleration = std::max(-1.0, std::min(1.0, angularAcceleration));

    grip += 0.01 * (1 - grip);
    speed += 0.006 * grip * translationAcceleration * (6 - abs(speed));

    if ((speed > 0) != (translationAcceleration > 0)) // Bremsing
        speed += 0.03 * grip * translationAcceleration;

    angle += 0.03 * grip * angularAcceleration;
    x += speed * cos(angle);
    y += speed * sin(angle);
}

double angleBetween(std::pair<double, double> vec1, std::pair<double, double> vec2)
	// Returnerer vinkel mellom to vektorar i radianar.
{
	double dot = vec1.first * vec2.first + vec1.second * vec2.second;
	double det = vec1.first * vec2.second - vec1.second * vec2.first;
	return atan2(det, dot);
}

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
    if (state.x > screenWidth) state.x = 0; //Denne fungerer heller ikke? Jeg gjør jo det samme som i de to som skjekker 0?
    if (state.x < 0) state.x = 0;
    if (state.y < 0) state.y = 0;
    if (state.y > screenHeight) state.y = 0; //Får den ikke til å stoppe nede og til høyre på skjermen? Gir ikke mening?
    drawBody();
}

void PlayerVehicle::drawBody(){
    fl_color(FL_BLUE);
    fl_pie(state.x, state.y, vehicleRadius*2, vehicleRadius*2, 0, 360);
    fl_color(FL_MAGENTA);
    fl_begin_polygon(); //Figure out this later! 
    fl_arc(state.x+cos(state.angle), state.y+sin(state.angle), vehicleRadius, 0, 180);
    fl_end_polygon();
}

std::pair<double, double> PlayerVehicle::steer() const {
    double translationAccelerationGas{0.7};
    double translationAccelerationTurn{0.1};
    double translationAccelerationBrake{-0.9};
    double angularAcceleration{0.9};
    if (Fl::event_key(FL_Up)) return std::make_pair(translationAccelerationGas, 0);
    else if (Fl::event_key(FL_Left)) return std::make_pair(translationAccelerationTurn, -angularAcceleration);
    else if (Fl::event_key(FL_Right)) return std::make_pair(translationAccelerationTurn, angularAcceleration);
    else if (Fl::event_key(FL_Down)) return std::make_pair(translationAccelerationBrake, 0);
    else return std::make_pair(0,0); 
}

Track::Track():Fl_Widget{10, 10, 10, 10}{
    //Make random track and push to goals-vector!
}

void Track::draw(){
    //Draw the points from goals-vector!
    fl_color(FL_BLACK);
    //for point in goals: Draw arc
}

bool circleCollision(double delX, double delY, double sumR){
    //Maths
}
