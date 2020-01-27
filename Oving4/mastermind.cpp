#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"

void playMastermind(){
    constexpr int size{4};
    constexpr int letters{6};
    /* Constexpr is used here because we know these values at compile time
    They are invaluable to the function of the game. 
    Could use const if we want the user to be able to define these values before playing (E.G.)
    This would make the game more customizable to the user. 
    */
    string code;
    string guess;

    code = randomizeString(size, 'A', 'A' + letters - 1);
    cout << code << endl; 
    guess = readInputToString(size, 'A', 'A' + letters - 1);

   
}

int checkCharactersAndPosition(){
    
}
