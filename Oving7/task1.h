#include "std_lib_facilities.h"

class Animal{
protected: 
    string name; 
    int age; 
public: 
    Animal(string name, int age):name{name}, age{age}{};
    virtual string toString(){ return "Animal: "+to_string(name)+","+to_string(age); }
    //Usikker på om denne funk virker per nå. Ikke testet enda. 

};

class Cat : public Animal{
public: 
    //tror ikke at dette er rett måte å gjøre det på!?
    Cat(){ Animal::Animal(name, age) };
    string toString(){ return "Cat: "+to_string(name)+","+to_string(age); }
};

class Dog : public Animal{
public: 

    string toString(){ return "Dog: "+to_string(name)+","+to_string(age); }
};
