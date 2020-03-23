#include "task1.h"
#include "task2.h"
#include "LinkedList.h"

int main(){
    /* //task 1
    testTask1Vec();
    cout << endl << endl;
    testTask1Set();
    cout << endl << endl;
    */

    /*    //Task 2: 
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
    */

    //Task 3:
    /* Tenk over følgende: Hvorfor er medlemsvariabelen prev i Norde av typen
       Node* og ikke en std::unique_ptr? 
       Mitt svar: Fordi vi ikke ønsker at det neste leddet i den lenkede lista
       skal "eie" det forrige elementet. Det ville betydd at hvis vi vil fjerne
       det neste elementet så måtte vi passet på at det forrige elementet ikke blir 
       fjernet også (dette er vanskelig og ulogisk). Det neste elementet i lista
       er derimot en unpique_ptr for at man skal kunne slette hele lista når man sletter
       det første elementet. Under sletting av et enkelt element må man dermed bare passe 
       på at man releaser eller mover eierskapet til pointeren over til et annet element. 
       Kan ikke tenke meg en annen grunn 
       enn dette (?). 
    */
}
