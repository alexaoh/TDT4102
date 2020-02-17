#include "std_lib_facilities.h"
#include "task1.h"
#include "Graph.h"

void testAnimal(){
    using namespace Graph_lib;
    
    //Animal test1{"Alexander", 16};
    //Animal test2{"Johnny", 80};
    Dog Rotty{"Bjørn", 6};
    Dog sjefen{"Kølla", 7};
    Cat Katja{"Katja Katt", 2};
    Cat Jitty{"Jitte", 101};
    /*
    cout << "This is " << test1.toString() << endl;
    cout << "This is " << Rotty.toString() << endl;
    cout << "This is " << Katja.toString() << endl;
    */

    Vector_ref<Animal> animals; 
    //animals.push_back(test1);
    //animals.push_back(test2);
    animals.push_back(Rotty);
    animals.push_back(sjefen);
    animals.push_back(Katja);
    animals.push_back(Jitty);

    //range-based for loop fungerte ikke her?!
    for (int i = 0; i<animals.size();i++){
        cout << animals[i].toString() << endl; 
    }

    //ved å fjerne virtual i Animal-klassen vil ikke toString()
    //kunne overskrives i Dog og Cat!

}
