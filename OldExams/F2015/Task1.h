#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;
/*
char* createAlphabet(char start, int length){
    //char alphabet[length]; //This table-size cannot be given at runtime! Has to be known before compile. 
    //Solution: 
    char* alphabet = new char[length];
    for (int i = 0; i < length; ++i){
        alphabet[i] = start++;
    }
    return alphabet; //The char-pointer alphabet gets destroyed upon leaving the scope, since it is not implemented dynamically. 
}
*/

bool isAnagram(const string& a, const string& b);
bool isPalindrome(const string& str);
void printWordStatistics(const string& filename);
double mean(double arr[], int size);
double median(int arr[], int size);
double round(double num, int precision);
