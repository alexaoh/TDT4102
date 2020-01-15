#include "Simple_window.h"

int maxOfTwo(int a, int b){
	if (a>b){
		cout << "A is greater than B" << '\n';
		return a;
	} else {
		cout << "B is greater than or equal to A" << '\n';
		return b;
	} 
}

int fibonacci(int n){
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << '\n';
	for (int x = 1; x < n + 1; x++){
		cout << x << "\t" << b << endl;
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----";
	return b;
}

int squareNumberSum(int n){
	int totalSum = 0;
	for (int i = 0; i < n+1; i++){
		totalSum += i*i;
		cout << i*i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

int triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while (acc < n){
		cout << acc << endl;
		acc += num; 
		num++;
	}
	cout << endl;
	return 0;
}

bool isPrime(int n){ 
	for (int j = 2; j < n; j++){
		if (n%j == 0){
			return false;
		}
	}
	return true;
}

int naivePrimeNumberSearch(int n){
	for (int number = 2; number < n; number++){
		if (isPrime(number)){ 
			cout << number << " is a prime" << endl;
		}
	}
	return 0;
}

int findGreatestDivisor(int n){
	for (int divisor = n-1; divisor >= 0; divisor--){
		if (n%divisor == 0){
			return divisor;
		}
	}
	return 1;
}

int main(){
	/* 
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5,6) << '\n';
	*/

	/* 
	cout << "Oppgave c)\n";
	cout << fibonacci(8) << "\n";
	keep_window_open();
	*/

	/*
	cout << "Oppgave d)\n";
	cout << squareNumberSum(3) << endl;
	*/

	/*
	cout << "Oppgave e)\n";
	cout << triangleNumbersBelow(13) << endl;
	*/
	
	/*
	cout << "Oppgave f)\n";
	cout << boolalpha << isPrime(5) << endl;
	*/
	/* Comment: 
	Without boolalpha the function returns:
		0 if false
		1 if true
	*/

	/*
	cout << "Oppgave g)\n";
	naivePrimeNumberSearch(22);
	*/

	/*
	cout << "Oppgave h)\n";
	cout << findGreatestDivisor(24) << endl;
	*/

	return 0; //This is here because I think all functions need to return a value. 


}
