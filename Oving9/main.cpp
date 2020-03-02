#include "iostream"
#include "Matrix.h"

using namespace std;

void fillInFibonacciNumbers(int result[], int length);
void printArray(int arr[], int length);
void createFibonacci();

int main(){

	//Task 1: createFibonacci();

	//Task 2: 
	Matrix tabell{2,2};
	
	for (int i = 0; tabell.getRows(); i++){
		for (int e = 0; tabell.getColumns(); e++){
			cout << tabell[i][e] << " "; //dette fungerer åpenbart ikke enda!
		}
	}
	
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
