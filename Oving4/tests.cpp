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


void printVector(vector<int> vec){
    for (auto x : vec){
        cout << x << endl;
    }
}
