#include "Task3.h"

Meeting::Meeting(int day, int start, int end, Campus location, Person* owner):
day{day}, start{start}, end{end}, location{location}, owner{owner}, next{allMeetings}, driver{nullptr}, firstPart{nullptr}{
    allMeetings = this;
}

void Meeting::addParticipant(Person* person){
    Participant* newPerson = new Participant{person};
    Participant* p = firstPart;
    if (!p) firstPart = newPerson;
    else{
        while(p->getNext()){
            p = p->getNext();    
        }
        p->setNext(newPerson);
    }
}

void Meeting::printCoDriving(){
    Meeting* m = allMeetings;
    if (!m) std::cout << "There are no meetings now" << std::endl;
    else{
        std::cout << "Possible co-driving for meeting in " << location << " on day " << day << " from " << start << " to " << end << " by <" << owner->getEmail() << ">" << std::endl;
        while(m){
            if (m->day == day && m->start == start && m->end == end && m->location == location && m != this){
                std::cout << "  Meeting by <" << owner->getEmail() << ">" << std::endl;
            }
            m = m->next;
        }
    }
    
} 

Meeting::~Meeting(){
    Participant* p = firstPart;
    while (p){
        Participant* help = p;
        delete p;
        p = help->getNext();
    }
}
