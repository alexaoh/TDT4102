#include "task1.h"
#include "task2.h"

int main(){
    /* //task 1
    testTask1Vec();
    cout << endl << endl;
    testTask1Set();
    cout << endl << endl;
    */

    //Task 2: 
    list<Person> personList;
    Person Jon{"Jon", "Arne"};
    Person Hans{"Hans", "Majestet"};
    Person Jonas{"Jonas", "Persson"};
    Person Z{"Mama", "Zinatra"};
    Person A{"Andres", "AAAb"};

    insertOrdered(personList, A);
    insertOrdered(personList, Jon);
    insertOrdered(personList, Z);
    insertOrdered(personList, Hans);
    insertOrdered(personList, Jonas);

    for (auto x : personList){
        cout << x << endl; 
    }


}
