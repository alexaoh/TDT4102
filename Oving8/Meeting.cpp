#include "std_lib_facilities.h"
#include "Meeting.h"

set<const Meeting*> Meeting::meetings;
//hvorfor må det initialiseres også her? Pga static?

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader):
day{day}, startTime{startTime}, endTime{endTime}, location{location}, subject{subject}, leader{leader}{
    participants.insert(leader);
    meetings.insert(this); //This is a pointer that points to the object for which the member function was called. 
}

vector<string> Meeting::getParticipantList(){
    vector<string> names;
    for (auto person : participants){
        names.push_back(person->getName());
    }
    return names;
}

ostream& operator<< (ostream& os, Campus& c){
    map<Campus, string> CampusToString;
    CampusToString[Campus::Trondheim] = "Trondheim";
    CampusToString[Campus::Ålesund] = "Ålesund";
    CampusToString[Campus::Gjøvik] = "Gjøvik";

    os << CampusToString[c];
    return os;
}
//hvorfor ikke en friend av Meeting? Er dette rett måte å gjøre det på da?
//Nå bruker jeg getters, i stedet for de private variablene, siden jeg ikke har tilgang til dem uten friend. 
ostream& operator<<(ostream& os, Meeting& m){
    os << "Meeting: \n" 
       << "Subject: " << m.getSubject() << endl
       //<< "Location: " << m.getLocation() << endl //venter med denne for now
       //Skjønner ikke hvorfor den ikke fungerer?
       << "Start Time: " << m.getStartTime() << endl
       << "End Time: " << m.getEndTime() << endl
       << "Meeting leader: " << *m.getLeader() << endl;
    os << "List of participants: " << endl;
    for (auto part : m.getParticipantList()){
        os << part << " ";
    }
    return os << endl;
 
}


vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> personPtrs;
    for (auto meeting : meetings){
        if (meeting != this){
            if (meeting->location == this->location && meeting->day == this->day && abs(meeting->endTime - this->endTime)<=1 && abs(meeting->startTime - this->startTime)<=1){ 
            personPtrs.push_back(meeting->leader);
            }
        }
        
    }

    return personPtrs;
}
