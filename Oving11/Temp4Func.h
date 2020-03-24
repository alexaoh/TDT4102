#include <iostream>
#include "random"
#include <vector>


template<typename T>
T maximum(T one, T two){
    if (one > two){
        return one;
    } else return two;
}

template<typename T> 
void shuffle(vector<T>& vec){
    //Fisher-Yates shuffle Algorithm
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = vec.size()-1; i>0; --i){
        int randomNum = rand() % i;
        T temp = vec[i]; 
        vec[i] = vec[randomNum];
        vec[randomNum] = temp;
    }
} 

template<typename T>
void printVector(const vector<T>& vec){
    for (auto x : vec){
        cout << x << " ";
    }
}

