#include "Task4.h"

std::ostream& operator<<(std::ostream& out, Animal& a){
    return out << a.toString(); 
}

Animal* parseAnimal(std::string line){
    std::stringstream ss{line};
    std::string name; 
    std::string tmp;
    std::string type;
    int age;
    ss >> name >> tmp >> type >> tmp >> age;
    if (type == "Dog"){
        std::string color;
        ss >> tmp >> color;
        return new Dog{name, age, color};
    } else if (type == "Human"){
        return new Human{name, age};
    }
    return nullptr;
}

void parseFriends(std::map<std::string, Animal*>& animals, std::string line){
    std::stringstream ss{line};
    std::string name1;
    std::string name2;
    std::string tmp;
    ss >> name1 >> tmp >> name2 >> tmp >> tmp;
    try {
        Animal* anim1 = animals.at(name1);
        Animal* anim2 = animals.at(name2);
        anim1->addFriend(anim2);
        anim2->addFriend(anim1);
    }  
    catch(...){
        std::cerr << "At least one of the animals in line " << line << " do not exist (yet)!";
    }

}
std::map<std::string, Animal*> readAnimals(std::string filename){
    std::map<std::string, Animal*> animals;
    std::ifstream ist{filename};
    if (!ist) throw;
    std::string line;
    while (getline(ist, line)){
        std::stringstream ss{line};
        std::string name; 
        std::string tmp;
        ss >> name >> tmp;
        if (tmp == "the"){
            Animal* newAnimal = parseAnimal(line);
            if (newAnimal) animals[newAnimal->getName()] = newAnimal;
        } else if (tmp == "and"){
            parseFriends(animals, line);
        }
    }
    return animals;
}
