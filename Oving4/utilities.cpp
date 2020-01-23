#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++){
        startValue += increment; 
    }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes){
    for (int i = 0; i < numTimes; i++){
        startValue += increment; 
    }
    return startValue;
}
void swapNumbers(int& num1, int& num2){
    int dummy{0};
    dummy = num1; 
    num1 = num2; 
    num2 = dummy; 
    return; 
}

void randomizeVector(vector<int>& vec, int n){
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i<n; i++){
        int random_number = rand() % 101;
        vec.push_back(random_number);
    }
    return; 
}

void sortVector(vector<int>& vec){
    int i{1};
    while(i < vec.size()){
        int j = i;
        while(j > 0 && vec[j-1] > vec[j]){
            swapNumbers(vec[j],vec[j-1]);
            j--;
        }
        i++;
    }
}

double medianOfVector(const vector<int>& vec){
    double median{0.0};
    int length{static_cast<int>(vec.size())};
    if (length % 2 == 0){
        median = (vec[((length-2)/2)] + vec[(length/2)])/2.0;
    } else median = vec[(length-1)/2];
    return median; 
}

void printStudent(Student student){
    cout << "This will print the attributes of the given student: " << endl; 
    cout << "Name: " << student.name << endl; 
    cout << "Study Program: " << student.studyProgram << endl; 
    cout << "Age: " << student.age << endl; 
    return;
}

string randomizeString(int characters, char lowerLimit, char upperLimit){
    string randomString;
    int lowLim = lowerLimit;
    int uppLim = upperLimit;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i<characters; i++){
        char random_letter = rand() % (uppLim - lowLim + 1) + lowLim;
        randomString.push_back(random_letter);
    }

    return randomString;
}

string readInputToString(int characters, char lowerLimit, char upperLimit);
