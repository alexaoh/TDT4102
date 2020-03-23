#include "task2.h"

ostream& operator<<(ostream& os, Person p){
    os << "First name: " << p.firstName << ", surname: " << p.surname;
    return os; 
}

void insertOrdered(list<Person>& l, const Person& p){ //ordered insertion, by surname
    bool inserted{false};
    for (list<Person>::iterator it = l.begin(); it != l.end(); ++it){
        if (p.getSurname() < it->getSurname()){
            l.insert(it, p);
            inserted = true;
        } 
    }
    if (!inserted){
        l.push_back(p);
    }
}
