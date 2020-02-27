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
    //lag en map for å få ut navnet på Campus!
    //Ev se i Øving 5 om man gjorde det på en annen måte der?!
    os << static_cast<Campus>(c);
    return os;
}
//hvorfor ikke en friend av Meeting? Er dette rett måte å gjøre det på da?
//Nå bruker jeg getters, i stedet for de private variablene, siden jeg ikke har tilgang til dem uten friend. 
ostream& operator<<(ostream& os, Meeting& m){
    os << "Meeting: \n" 
       << "Subject: " << m.getSubject() << endl
       << "Location: " << m.getLocation() << endl //her ser jeg hvordan Campus må overlastes! For å passe med utskriften! Vil ha ut navnet til Campus!
       << "Start Time: " << m.getStartTime() << endl
       << "End Time: " << m.getEndTime() << endl
       << "Meeting leader: " << m.getLeader() << endl;
    os << "List of participants: ";
    //legge til denne lista!
}
