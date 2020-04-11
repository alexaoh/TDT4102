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

//Classes Participant and Meeting are declred in the task description. 