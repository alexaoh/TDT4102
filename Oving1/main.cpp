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

int fibonacci(int n)[
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << '\n';
	for (int x = 1; x < n + 1; x += 1){
		cout << x << b;
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----";
	return b;
}

int main(){
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5,6) << '\n';
	Kommenter ut dette! Finn ut hvordan man kan kommentere!
}