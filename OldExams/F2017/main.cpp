#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

int main(){
    Dog dog{"Jake", 28, "orange"};
    Human human{"Finn", 12};
    std::cout << dog.toString() << std::endl;
    std::cout << human.toString() << std::endl;
    dog.addFriend(&human);
    human.addFriend(&dog);
    for (auto a : dog.getFriends()){
        std::cout << dog << " and " << *a << " are friends " << std::endl;
    }
    return 0;
}

//Utskrift dersom Animal::toString() er virtual:
/* 
    Jake the Dog
    Finn the Human
    Jake the Dog and Finn the Human are friends
*/

//Utskrift dersom Animal::toString() ikke er virtual:
/*
    Jake the Dog
    Finn the Human
    Jake the Animal and Finn the Animal are friends
*/