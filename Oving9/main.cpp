#include "iostream"
#include "Matrix.h"
#include "dummyTest.h"

using namespace std;

void fillInFibonacciNumbers(int result[], int length);
void printArray(int arr[], int length);
void createFibonacci();

int main(){

	//Task 1: createFibonacci();

	
	//Task 2: 

	Matrix zeros{3,5}; // makes array filled with zeros. 
	cout << zeros.get(1,1) << endl;
	zeros.set(1,1,13.0);
	cout << zeros.get(1,1) << endl;
	
	Matrix identity{5}; // makes 5x5 identity matrix.
	cout << identity.get(0,0) << endl;
	identity.set(1,1,13.0);
	cout << identity.get(1,1) << endl;

	Matrix nonValid;
	cout << boolalpha << nonValid.isValid() << endl;
	cout << boolalpha << identity.isValid() << endl;

	cout << zeros << endl;
	cout << identity << endl;
	identity.set(1,3,55.0);
	cout << identity << endl;

	//Task 3: Intermezzo: Kopiering og tilordning
	/*
	a) Hva skrives ut?
	Mitt svar: 
	a: 4
	b: 4
	c: 4

	a: 5
	b: 5
	c: 5
	Tenker dette siden alle peker til den samme num-pekeren.
	Tester koden nedenfor: 
	--> svaret mitt ovenfor stemte! Dette er fordi pekere utfører shallow copy: de kopierer kun pekeren, ikke hva pekeren peker til (slik som i deep copy)
	Programmet crasher på slutten (tror jeg) fordi den samme destruktoren blir kalt for både a, b og c, selv om det ikke er flere elementer igjen etter a er destroyed (siden de deler elementer!)
	*/

	//dummyTest();
	
}


void fillInFibonacciNumbers(int result[], int length){
	int fib1{0};
	int fib2{1};
	result[0] = fib1;
	result[1] = fib2;
	for (int i = 2; i<length; i++){
		int fib3{fib1+fib2};
		result[i] = fib3;
		fib1 = fib2;
		fib2 = fib3;
	}
}

void printArray(int arr[], int length){
	for (int i = 0; i<length;i++){
		cout << arr[i] << " ";
	}
}

void createFibonacci(){
	cout << "How many numbers should be allocated? " << endl;
	int amount;
	cin >> amount;
	int *arr = new int[amount];
	fillInFibonacciNumbers(arr, amount);
	printArray(arr, amount);
	delete[] arr;
	arr = nullptr;
}
