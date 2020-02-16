#include "std_lib_facilities.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"

void addSubjects(CourseCatalog& catalog);

int main()
{
	//Task 1: 
	//writeToFile();
	//linenumber();

	//Task 2: 
	//charCounterInFile();

	CourseCatalog NTNU;
	/*
	NTNU.addCourse("TDT4102", "Object oriented programming in C++");
	NTNU.addCourse("TMA4120", "Matematikk 4K");
	try{

	NTNU.getCourse("TDT4102");
	NTNU.getCourse("TDG3829"); //Should throw exception
	}
	catch(...){
		cout << "The course you are trying to get does not exist. ";
	}

	cout << NTNU;

	NTNU.removeCourse("TDT4102");

	cout << NTNU;
	*/

	//addSubjects(NTNU);
	//cout << NTNU;

	//NTNU.writeToFile("test.txt"); //Denne virker som den skal
	//NTNU.readFromFile("test.txt"); // får ikke denne til å virke! Prøv mer senere!
	//cout << NTNU;


}

//Function from task 3c, to test CourseCatalog. 
void addSubjects(CourseCatalog& catalog){
	catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	catalog.addCourse("TMA4100", "Matematikk 1");

	//operator[] overwrites the existing key-value pair
	//insert() inserts if it does not exist, but does not overwrite if it exists. 
	catalog.addCourse("TDT4102", "C++");

	return; 
}
