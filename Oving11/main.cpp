#include "task1.h"
#include "task2.h"
#include "LinkedList.h"
#include "Temp4Func.h"

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
    
    b) Svar på følgende teorispørsmål: 
    * Du har i de tidligere øvingene hovedsakelig brukt std::vector som beholder.
      Imidlertid vil det i noen tilfeller være et bedre valg å bruke liste. Når er
      lenkede lister bedre, og hvorfor? 
    Mitt svar: Bedre når du vil kunne beholde pointere til elementene slik de opprinnelig var definert,
      slik at ingen iteratorer blir ugyldige, slik som kan skje når man f.eks sletter 
      eller inserter et element i en vektor. Fordi størrelsen til vektor må endres under disse 
      operasjonene, vil pekerne ofte kunne bli ugyldige (peke til et annet objekt enn antatt). 
      I tillegg vil det gå raskere å inserte og slette i en liste, fordi man kun trenger å 
      endre på noen pekere per objekt, i stedet for å passe på at vektoren har rett size 
      og nok minne f.eks. Man kan derimot ikke bruke random oppslag i lister. 
    * Den lenkede listen du nettopp lagde kan brukes til å implementere andre datastrukturer
      på en lett måte. Forklar hvordan du ville brukt LinkedList-klassen for å implementere
      en stack eller queue.
    Nitt svar: En stack er LIFO, mens en queue er FIFO. Dette er lenkede lister også, bare at de 
      trenger ekstra medlemsfunksjoner for å fungere som man ønsker. Stack er veldig enkel å implementere; 
      man trenger å kunne legge elementer til bakerst, og ha en unique pointer fra den forrige som var øverst, 
      til den ny øverste. Når en node skal fjernes er det bare å fjerne denne pointeren og ha en pointer til end() igjen. 
      Queue kan implementeres på nesten samme måte; Her skal det legges til elementer bakerst i stedet. Dette 
      er litt mer krevende, da det å lages en unique ptr til det tidligere bakerste elementet. Deretter vil det 
      fjernes elementer fra toppen, slik som i stack. Håper dette er et tilfredsstillende svar på oppgaven. 
    */  

    //Task 4
    /*
    int a = 1; 
    int b = 2;
    int x = maximum(a,b);
    double d = 2.4;
    double e = 3.2; 
    double f = maximum(d,e);
    std::cout << x << " " << f << endl;
    */
    // For at denne skal virke for andre typer, må >-operatoren være overlastet og fungerende! 

    vector<int> a{1,2,3,4,5,6,7};
    shuffle(a);
    printVector(a);

    cout << endl; 
    vector<double> b{1.2,2.2,3.3,4.2};
    shuffle(b);
    printVector(b);

    cout << endl; 
    vector<string> c{"one", "two", "three", "four"};
    shuffle(c);
    printVector(c);


}

