#include <string>
#include <random>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;

class Creature{
    string name;
    int hitpoints;
    int strength;
    int defence;
protected:
    virtual int doDmg(){ return rand() % strength +1; }
    virtual void takeDmg(int dmg){ hitpoints -= max(dmg-defence, 0); }
public:
    Creature(string name):name{name}, strength{100}, hitpoints{1000}, defence{10}{}
    bool isAlive(){ return hitpoints >0; }
    void attack(Creature& c){ c.takeDmg(this->doDmg()); }
};

class Demon : public Creature{
protected: 
    int doDmg() override { return Creature::doDmg()*1.10; }
public: 
    Demon(string name):Creature(name){}
};

class Balrog : public Demon{
protected: 
    int doDmg() override { (rand() & 10 == 0) ? Creature::doDmg()*2 : Creature::doDmg(); }
public: 
    Balrog(string name):Demon{name}{}
};

void readFromFile(string filename, vector<Creature*> creatures){
    // Format, per line: Type, name
    ifstream ist{filename};
    string type; 
    string name;
    char comma;
    try{
        if (!ist) throw runtime_error("Could not open file "+filename);
        while(ist >> type >> comma >> name){
            if (type == "Creature"){
                creatures.push_back(new Creature{name});
            } else if (type == "Demon"){
                creatures.push_back(new Demon{name});
            } else if (type == "Balrog"){
                creatures.push_back(new Balrog{name});
            } else{
                throw runtime_error("Please give a valid Creature-type");
            }   
        }
        if (comma != ','){
            throw invalid_argument("Wrong formatting, use comma as a delimiter");
        }
    } catch(exception& exc){
        cerr << "An exception was caught: " << exc.what() << endl;
    }
}