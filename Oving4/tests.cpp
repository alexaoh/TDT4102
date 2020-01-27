#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

void printVector(vector<int> vec);

void testCallByValue(){
    int v0 = 5; 
    int increment = 2; 
    int iterations = 10; 
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result : " << result << endl; 
}

void testCallByReference(){
    int v0 = 5; 
    int increment = 2; 
    int iterations = 10; 
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result : " << result << endl;
}

void testVectorSorting(){
    vector<int> percentages;
    int n{11};
    randomizeVector(percentages, n);
    printVector(percentages);

    swapNumbers(percentages[0],percentages[1]);
    cout << "New print after swap: " << endl; 
    printVector(percentages);

    cout << "Find median before sort: " << endl; 
    cout << "Median: " << medianOfVector(percentages) << endl; 

    cout << "Testing to sort the vector now: " << endl;
    sortVector(percentages);
    printVector(percentages);

    cout << "Find median after sort: " << endl; 
    cout << "Median: " << medianOfVector(percentages) << endl; 
}

void testString(){
    string grades;
    char lowerlimit{'A'};
    char upperLimit{'F'};
    vector<int> gradeCount;
    cout << "Gradecount when declaring: ";
    printVector(gradeCount);
    grades = randomizeString(8, lowerlimit, upperLimit);
    cout << "The string is " << grades << ".\n"; 
    //Må vel finnes en mer effektiv måte å gjøre dette på!
    //Fyll en vektor vha lower og upper f.eks og loop gjennom.
    int amountOfA{countChar(grades, 'A')};
    int amountOfB{countChar(grades, 'B')};
    int amountOfC{countChar(grades, 'C')};
    int amountOfD{countChar(grades, 'D')};
    int amountOfE{countChar(grades, 'E')};
    int amountOfF{countChar(grades, 'F')};
    gradeCount.push_back(amountOfF);
    gradeCount.push_back(amountOfE);
    gradeCount.push_back(amountOfD);
    gradeCount.push_back(amountOfC);
    gradeCount.push_back(amountOfB); //LOL, spaghetti
    gradeCount.push_back(amountOfA);

    cout << "This is gradeCount: ";
    printVector(gradeCount);

    double average{0.0};
    double sum{0.0};
    for (unsigned int i = 0; i<gradeCount.size(); i++){
        sum += gradeCount[i]*i; 
    }
    average = sum/gradeCount.size();
    cout << "The grade average is " << average << endl; 


}


void printVector(vector<int> vec){
    for (auto x : vec){
        cout << x << endl;
    }
}
