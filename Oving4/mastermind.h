#include "std_lib_facilities.h"

void playMastermind();
int checkCharactersAndPosition(string code, string guess);
int checkCharacters(string code, string guess);

constexpr unsigned int sizing{4};
constexpr int letters{6}; //Choose f.ex A-F (6 letters)
constexpr int guesses{6};
