#include "cannonball.h"
#include "std_lib_facilities.h"

double acc1Y(){ //2c)
    return -9.81;
}

double ve1Y(double initVelocityY, double time){ //2b)
    return initVelocityY + acc1Y()*time;
} 

//2c)
double posX(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time;
}
double posY(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time + acc1Y()*pow(time, 2)/static_cast<double>(2);
}

//Is this the way the task wants me to do it?
void printTime(double sec){ //2d)
    int hours{static_cast<int>(sec)/3600};
    int mins{(static_cast<int>(sec)%3600)/60};
    //((sec/3600.0)-3600*hours)/60
    int secs{static_cast<int>(sec)%60};
    //(sec/60.0)-60*mins
    cout << "Number of hours: " << hours << endl; 
    cout << "Number of minutes: " << mins << endl; 
    cout << "Number of seconds: " << secs << endl; 
    return; 
}


double flightTime(double initVelocityY){ //2e)
    return (-2*initVelocityY)/static_cast<double>(acc1Y());
} 

//Task 4a)
double getUserInputTheta(){
    double deg{0.0};
    cout << "Degrees: " << endl; 
    cin >> deg;
    return deg;
}

double getUserInputAbsVelocity(){
    double absVel{0.0};
    cout << "Absolute velocity " << endl; 
    cin >> absVel;
    return absVel;
}

double degToRad(double deg){
    const double pi{3.1415926535359};
    return deg/180*pi;
}

double getVelocityX(double theta, double absVelocity){
    return getUserInputAbsVelocity()*cos(degToRad(theta));
}

double getVelocityY(double theta, double absVelocity){
    return getUserInputAbsVelocity()*sin(degToRad(theta));
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> v{getVelocityX, getVelocityY};
    return v;
}

//Task 4b)
double getDistanceTraveled(double velocityX, double velocityY){
    
}