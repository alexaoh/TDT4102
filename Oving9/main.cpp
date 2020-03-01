#include "iostream"


void fillInFibonacciNumbers(int result[], int length);
void printArray(int arr[], int length);
void createFibonacci();

int main(){

	//Task 1: createFibonacci();

	
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
		std::cout << arr[i] << " ";
	}
}

void createFibonacci(){
	std::cout << "How many numbers should be allocated? " << std::endl;
	int amount;
	std::cin >> amount;
	int *arr = new int[amount];
	fillInFibonacciNumbers(arr, amount);
	printArray(arr, amount);
	delete[] arr;
	arr = nullptr;
}
