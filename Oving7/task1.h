#include "std_lib_facilities.h"

class Animal{
protected: 
    string name; 
    int age; 
public: 
    Animal(string name, int age):name{name}, age{age}{};
    virtual string toString() = 0; //pure virtual function

};

class Cat : public Animal{
public: 
    Cat(string name, int age) : Animal{name, age}{};
    string toString() override { return "Cat: "+to_string(name)+", "+to_string(age); }
};

class Dog : public Animal{
public: 
    Dog(string name, int age) : Animal(name, age){};
    string toString() override { return "Dog: "+to_string(name)+", "+to_string(age); }
};

void testAnimal();
