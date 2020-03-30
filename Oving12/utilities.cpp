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
    if (state.x > screenWidth) state.x = 0;
    if (state.x < 0) state.x = 0;
    if (state.y < 0) state.y = 0;
    if (state.y > screenHeight) state.y = 0; //Får den ikke til å stoppe nede og til høyre på skjermen? Gir ikke mening?
    drawBody();
}

void PlayerVehicle::drawBody(){
    fl_color(FL_BLUE);
    fl_pie(state.x, state.y, 30, 30, 0, 360);
}

std::pair<double, double> PlayerVehicle::steer() const {
    double translationAcceleration{0.1};
    double translationAcceleration2{0.1};
    double angularAcceleration{0.7};
    double angularAcceleration2{0.4};
    if (Fl::event_key(FL_Up) || Fl::event_key('W')) return std::make_pair(translationAcceleration, -angularAcceleration);
    else if (Fl::event_key(FL_Left) || Fl::event_key('A')) return std::make_pair(translationAcceleration2, angularAcceleration2);
    else if (Fl::event_key(FL_Down) || Fl::event_key('S')) return std::make_pair(translationAcceleration, angularAcceleration);
    else if (Fl::event_key(FL_Right) || Fl::event_key('D')) return std::make_pair(translationAcceleration2, -angularAcceleration2);
    else return std::make_pair(0,0); 
}
