#include <iostream>
#include <list>

using namespace std;

class Person{
    string firstName;
    string surname;
public: 
    Person(string firstName, string surname):firstName{firstName}, surname{surname}{};
    string getFirstName() const { return firstName; }
    string getSurname() const { return surname; }
    friend ostream& operator<<(ostream& os, Person p); 

};

void insertOrdered(list<Person>& l, const Person& p);