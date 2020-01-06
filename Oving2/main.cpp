#include "std_lib_facilities.h"

//Task 1: 
void inputAndPrintInteger(){
	cout << "Skriv inn et tall: ";
	int x = 0;
	cin >> x;
	cout << "Du skrev: " << x << endl;
}

int inputInteger(){
	cout << "Skriv inn et tall: ";
	int x = 0;
	cin >> x;
	return x;
}

void inputIntegersAndPrintSum(){
	/*Teori d): Jeg valgte å bruke inputInteger fordi
				den andre printer på en annen måte enn 
				det som er ønskelig i denne oppgaven!
				Jeg trenger kun input fra bruker. 
	*/
	int x = inputInteger();
	int y = inputInteger();
	int sum = x + y;
	cout << "Summen av tallene: " << sum <<  endl;
}

bool isOdd(int n){
	if (n%2 == 1){
		return true;
	}
	return false;
}

void testIsOdd(){
	//I made this function to test isOdd in the interval [0,15]
	for (int i = 0; i <= 15; i++){
		bool x = isOdd(i);
		cout << "Tall: " << i << " gir " << std::boolalpha << x << endl;
	}
}

void printHumanReadableTime(int sec){
	int hours = sec / 3600;
	int min = (sec%3600) / 60;
	sec = sec % 60;
	cout << hours << " timer " << min << " minutter " << sec << " sekunder " << endl;
}

//Task 1 ends here. 

//Task 2, Løkker:
int main()
{
	
	keep_window_open();
}
