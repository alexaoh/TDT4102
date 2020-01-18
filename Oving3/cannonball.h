#include "std_lib_facilities.h"
double acc1Y(); //1a)

double ve1Y(double initVelocityY, double time); //1b)

//1c)
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double sec); //1d)

double flightTime(double initVelocityY); //1e)

//Task 4a)
double getUserInputTheta(); 
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
vector<double> getVelocityVector(double theta, double absVelocity);

//Task 4b) 
double getDistanceTraveled(double velocityX, double velocityY);

//Task 4c) 
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
