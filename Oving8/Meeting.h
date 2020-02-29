#include "std_lib_facilities.h"
#include "Person.h"
#include "Graph.h"

#pragma once

enum class Campus{
    Trondheim=1, Ålesund, Gjøvik
};

ostream& operator<< (ostream& os, Campus& c);

class Meeting{
    int day; 
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static set<const Meeting*> meetings;
public: 
    Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader);
    int getDay() const { return day; }
    int getStartTime() const { return startTime; }
    int getEndTime() const { return endTime; }
    Campus getLocation() const { return location; }
    string getSubject() const { return subject; }
    const Person* getLeader() const { return leader; }

    ~Meeting(){}

    void addParticipant(Person* p){ participants.insert(p); }
    //hvorfor fungerer addParticipant når Person* p ikke er const? 
    vector<string> getParticipantList();
    vector<const Person*> findPotentialCoDriving();
    //her fungere det IKKE uten const!
};

ostream& operator<<(ostream& os, Meeting& m);
