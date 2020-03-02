#include "iostream"
#include "Matrix.h"
#include "dummyTest.h"

using namespace std;

void fillInFibonacciNumbers(int result[], int length);
void printArray(int arr[], int length);
void createFibonacci();

int main(){

	//Task 1: createFibonacci();

	/*
	//Task 2: 
	Matrix tabell{2,2};
	
	for (int i = 0; tabell.getRows(); i++){
		for (int e = 0; tabell.getColumns(); e++){
			cout << tabell[i][e] << " "; //dette fungerer åpenbart ikke enda!
		}
	}
	*/

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
	dummyTest();
	
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
