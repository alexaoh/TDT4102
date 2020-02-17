#include "std_lib_facilities.h"
#include "task1.h"

int main()
{
	/*Task 1: 
    Forskjellen er på public, private og protected er: 
    - Public => Alle har tilgang til dataene
    - Private => Kun medlemsfunskjoner i samme klasse/struct har tilgang til dataene
    - Protected => Kun "childs", dvs klasser som arver fra den gitte klassen, 
                kan få tak i dataene/benytte funksjonene som står der. 
                Dette sikrer at den gitte klassen kun brukes som abstract klasse, 
                som f.eks Shape-klassen i Graph_lib (ikke mulig å lage objekter av den). 

    */

   testAnimal();
}
