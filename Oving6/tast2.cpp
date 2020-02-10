#include "std_lib_facilities.h"
#include "task2.h"

void charCounterInFile(){
    string iname = "grunnlov.txt";
    ifstream ist{iname};
    if (!ist) error("Can't open input file, ", iname);

    map<char, int> characterMap;
    char character{'a'};
    while (ist >> character){
    isalpha(character) ? characterMap[tolower(character)]++ : false ; 
    }

    for (const auto x : characterMap){
        cout << x.first << ": " << x.second << endl;
    }

}
