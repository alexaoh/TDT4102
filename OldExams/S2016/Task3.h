#include <iostream>

class Person {
    int id;
    std::string email;
public: 
    Person(int id, std::string email):id{id}, email{email}{};
    const int getId() const { return id; }
    const std::string getEmail() const { return email; }
    void setEmail(std::string mail) { email = mail; }
};

class Driver : public Person{
    std::string carType;
    int freeSeats;
public:
    Driver(std::string carType, int freeSeats, int id, std::string email):
    Person{id, email},carType{carType}, freeSeats{freeSeats}{};
};

//Classes Participant and Meeting are declared fully in the task description. 

enum Campus { TRH, AAL, GJO };

class Participant{
    Person* who;
    Participant* next;
public:
    Participant(Person* who):who{who}, next{nullptr}{};
    Person* getWho() { return who; }
    void setNext(Participant* next){ this-> next = next; }
    Participant* getNext(){ return next; }

};

class Meeting{
    int day;
    int start; 
    int end;
    Campus location;
    Person* owner;
    Driver* driver;
    Meeting* next;
    Participant* firstPart;
public: 
    Meeting(int day, int start, int end, Campus location, Person* owner);
    ~Meeting();
    Meeting* getNext() { return next; }
    void addParticipant(Person* person);
    Participant* getParticipants() { return firstPart; }
    void printCoDriving();
};

Meeting* allMeetings = nullptr; 
