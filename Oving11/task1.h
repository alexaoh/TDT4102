#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

vector<string> task1Vec(){
    vector<string> myVec{"hello", "my", "Dear", "Friend", "hello"};

    for (vector<string>::iterator it = myVec.begin(); it != myVec.end(); ++it){
        cout << *it << " ";
    }

    cout << endl;

    for (vector<string>::reverse_iterator rit = myVec.rbegin(); rit != myVec.rend(); ++rit){
        cout << *rit << " ";
    }

    return myVec;
}   

void replaceVec(vector<string>& vec, string old, string replacement){
    vector<string>::iterator oldFound = vec.begin();
    while (oldFound != vec.end()){
        oldFound = find(oldFound, vec.end(), old);
        if (oldFound != vec.end()){
            vec.erase(oldFound);
            vec.insert(oldFound, replacement);
        }
        oldFound++;
    }
}

void testTask1Vec(){
    vector<string> myVec = task1Vec();
    replaceVec(myVec, "hello", "heisann");
    
    cout << endl; 

    for (auto x : myVec){
        cout << x << " ";
    }

}

//Repeat the task with a set!

set<string> task1Set(){ //return value set
    set<string> mySet{"hello", "this", "is", "is", "my", "set", "hello"};

    for (set<string>::iterator it = mySet.begin(); it != mySet.end(); ++it){
        cout << *it << " ";
    }

    cout << endl;

    for (set<string>::reverse_iterator rit = mySet.rbegin(); rit != mySet.rend(); ++rit){
        cout << *rit << " ";
    }

    return mySet;
}

void replaceSet(set<string>& s, string old, string replacement){
    //Unnecessary with a loop here, since the entries in a set are unique. 
    set<string>::iterator oldFound = find(s.begin(), s.end(), old);
    if (oldFound != s.end()){
        s.insert(oldFound, replacement);
        s.erase(oldFound);
        
    }
}

void testTask1Set(){
    set<string> mySet = task1Set();
    replaceSet(mySet, "hello", "heisann");
    
    cout << endl; 

    for (auto x : mySet){
        cout << x << " ";
    }
}

//The code is identical for sets and vectors. Should therefore ideally use templates. 
