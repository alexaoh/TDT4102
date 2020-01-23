#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

/*Task 1a) Kodeforståelse: 
Verdien som blir skrevet ut for v0 er 5. 
Dette skyldes at v0 sendes inn som verdi/kopi (pass by value), 
overskrides heller ikke på utsiden av funksjonen (i main)
25 skrives derimot ut som result, fordi denne variabelen "tar endringene". 
*/



int main()
{
	//Lag en testmeny (bedre enn i Oving2! senere.
	//En som tar seg av errors (try-catch e.l), se teori. 
	//Forbedre menyen på den måten!!!
	
	int userInput{0};
	do{
		cout << "Choose an option from the menu: " << endl;
		cout << "0) Quit " << endl;  
		cout << "1) testCallByValue() " << endl; 
		cout << "2) testCallByReference() " << endl; 
		cout << "3) swapNumbers() " << endl; 
		cout << "4) testVectorSorting() " << endl; 
		cout << "5) printStudent() " << endl;
		cout << "6) testString() " << endl;
		cout << "7) readInputToString() " << endl;
		cin >> userInput;
		switch(userInput){
			case 1: 
				testCallByValue();
				break; 
			case 2: 
				testCallByReference();
				break; 
			case 3: {
				//I used pass-by-reference because it makes it
				//easier to swap the values directly, instead
				//of juggling more variables. 
				int num1{0};
				int num2{0};
				cout << "Swap two integers: (a b) " << endl;
				cin >> num1 >> num2;
				swapNumbers(num1, num2);
				cout << "The former num1 is now " << num1 
					 << " and the former num2 is now " << num2 << endl; 
				break; 
				}
			case 4: 
				testVectorSorting();
				break;
				//JA, jeg får ulike svar før og etter den sorterte vektoren! (Naturligvis!)
			case 5: {
				//Need to fix error-handling here aswell!!!
				Student new_student; 
				cin.ignore(); //The userinput leaves a \n in the stream, which skips the getline new_student.name
				//if this ignore is removed. Can this be solved more generally? Or should this ignore be added everywhere?
				//These problems could happen anywhere!!
				cout << "Register a student! Write: " << endl; 
				cout << "Name: " << endl; 
				getline(cin, new_student.name);
				cout << "Study Program: " << endl; 
				getline(cin, new_student.studyProgram);
				cout << "Age: " << endl; 
				cin >> new_student.age;
				printStudent(new_student);
				break; 
				}
			case 6: 
				testString();
				break;
			case 7: 
				//this function is skipped for now!
				readInputToString;
				break;
			default: 
				cout << "Try again. ";
		}
	} while(userInput!=0);
	
	keep_window_open();
}
