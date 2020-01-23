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
    //Study this a bit more also!
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

//Skipping this for now!
string readInputToString(int characters, char lowerLimit, char upperLimit){
    string text;
    cout << "Fill the string with characters between " << lowerLimit << " and " << upperLimit << ".\n";
    string filling; 
    int low = lowerLimit;
    int upper = upperLimit;
    
   // int fillingNumber = filling; //Fungerer kun med char naturligvis!
    //Sjekk at jeg har tolket oppgaven rett!
    //While-loop?
    //Use try-cath-exceptions maybe? Find out!
    //This solution feels sub-optimal, but try it first!
    while(text.size() != characters){
        getline(cin, filling);
        //toupper(filling); //You get the idea for now. Try more later!
        for (auto x : filling){
            int in = x;
            if (in>low && in<upper){
                text.push_back(x);
            }
            else{
                cout << "Please give new and correct input" << endl;
                break;
            }
        
        }
    }

    return text;    
}

int countChar(string text, char letter){
    int amount{0};
    for (char x : text){
        if (x == letter){
            amount++;
        } 
    }
    return amount;
}
