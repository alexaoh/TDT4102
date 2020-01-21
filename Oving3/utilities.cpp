#include "utilities.h"
#include "std_lib_facilities.h"
#include "cannonball.h"
#include "cannonball_viz.h"

int randomWithLimits(int lowerLimit, int upperLimit){
    //Skjønner ikke helt hvordan man setter upper og lower limit
    //Hvorfor fungerer dette med moduloen?
    int random_number = rand() % (upperLimit+1-lowerLimit) + lowerLimit;
    //Added the +1 so that the upperLimit also can be returned. 
    //I do not understand quite how this works?

    return random_number;
}

string checkLongerOrShorter(double distanceToTheTarget){
    string text{"Longer or shorter"};
    if (distanceToTheTarget < 0){
        text = " for kort";
    }
    else if (distanceToTheTarget > 0){
        text = " for langt";
    }
    return text;
}

void playTargetPractice(){
    int numberOfTries{3};
    do {
        double radians{degToRad(getUserInputTheta())};
        double initVel{getUserInputAbsVelocity()};

        vector<double> velVector{getVelocityVector(radians, initVel)};
        cout << velVector[1];

        int minFieldLength{100};
        int maxFieldLength{1000};
        int targetPosition{randomWithLimits(minFieldLength, maxFieldLength)};

        //Distance to the randomized target
        double distanceToTarget{targetPractice(targetPosition, velVector[0], velVector[1])};

        double travelTime{flightTime(velVector[1])};

        string longerOrShorter{checkLongerOrShorter(distanceToTarget)};

        cannonBallViz(targetPosition, maxFieldLength, velVector[0], velVector[1], 5);


        if (abs(distanceToTarget) <= 5){
            cout << "Gratulerer! Du har vunnet!";
            break;
        }
        else{
            cout << "Avstanden til målet er: " << distanceToTarget << longerOrShorter << endl; 
            cout << "Kulen har brukt følgende tid på reisen: " << endl; 
            printTime(travelTime);
            numberOfTries--;
        }

        
    } while (numberOfTries > 0);

    cout << "Du har dessverre tapt. Prøv gjerne igjen. ";
    

}
