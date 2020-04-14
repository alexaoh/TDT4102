#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include <map>

class Animal {
protected: //alle disse bør deklarerer som protected, slik at de kan brukes av child-klasser. 
    std::string name;
    int age; 
    std::vector<Animal*> friends;
public: 
    Animal(std::string name, int age):name{name}, age{age}{}
    virtual std::string toString() { return name + " the Animal"; }
    void addFriend(Animal* a){ friends.push_back(a); }
    std::vector<Animal*> getFriends(){ return friends; }
    std::string getName() { return name; }

};

class Dog : public Animal {
protected:
    std::string color; 
public:
    Dog(std::string name, int age, std::string color):Animal{name, age}, color{color}{}
    virtual std::string toString() override { return name + " the Dog"; }

};

class Human : public Animal {
public: 
    Human(std::string name, int age):Animal{name, age}{}
    virtual std::string toString() override { return name + " the Human"; }

};

std::ostream& operator<<(std::ostream& out, Animal& a);

Animal* parseAnimal(std::string line);
void parseFriends(std::map<std::string, Animal*>&animals, std::string line);
std::map<std::string, Animal*> readAnimals(std::string filename);
