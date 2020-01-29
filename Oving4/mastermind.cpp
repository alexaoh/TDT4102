#include "std_lib_facilities.h"
#include "utilities.h"
#include "masterVisual.h"

void playMastermind(){
    /* Constexpr is used here because we know these values at compile time
    They are invaluable to the function of the game. 
    Could use const if we want the user to be able to define these values before playing (E.G.)
    This would make the game more customizable to the user. 
    */
    string code;
    string guess;
    int amountOfGuesses = guesses;
    int round{1};

    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    

    code = randomizeString(sizing, 'A', 'A' + letters - 1);
    cout << code << endl; 
    addGuess(mwin, code, code.size(), code[0], 0);
    //hideCode(mwin, sizing);
    do{
        guess = mwin.getInput(sizing, 'A', 'A' + letters - 1);

        int correctCharacter{checkCharacters(code, guess)};
        int correctPosition{ checkCharactersAndPosition(code, guess)};
        addGuess(mwin, guess, guess.size(), code[0], round);
        addFeedback(mwin, correctPosition,correctCharacter, sizing, round);

        if (guess == code){
            cout << "Congratz! You won!";
            break;
        }
        cout << "Amount of correct characters: " << correctCharacter << endl; 
        cout << "Characters in the correct spot: " << correctPosition << endl; 
        amountOfGuesses--;
        round++;
        
    }
    while (checkCharactersAndPosition(code,guess) < sizing && guesses > 0);

    mwin.redraw();
    
    //Hvordan sjekke om han har vunnet eller tapt het ute?!
    cout << "I am sorry, you lost. Try again. " << endl; 
    return; 
   
}

int checkCharactersAndPosition(string code, string guess){
    int number1{0};

    for (int i = 0; i<code.size(); i++){
        (code[i] == guess[i]) ? number1 += 1 : number1; 
    }

    return number1; 

}
int checkCharacters(string code, string guess){
    int number1{0};

    for (int i = 0; i<code.size(); i++){
        for (int j = 0;j<guess.size(); j++){
            if (code[i] == guess[j]){
                number1 += 1;
                guess = guess.substr(0,j) + guess.substr(j+1);
                break;
            }
        }
    }

    return code.size() - guess.size();

}
