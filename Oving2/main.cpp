#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

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

	//a)
void readAndWriteSumOfIntegers(){
	cout << "Skriv inn antall tall du vil summere: " << endl;
	int antall{0};
	cin >> antall; 
	int sum{0};
	for (int i = 0; i < antall; ++i){
		cout << "Tall: " << endl;
		int tall{0};
		cin >> tall;
		sum = sum + tall;
	}
	cout << "Summen er: " << sum << endl;
	return;
}

	//b)
void readAndSumIntegersWhile(){
	int tall{0};
	int sum{0};
	do {
		cout << "Skriv inn et tall. Jeg ber om flere tall helt til du skriver \"0\"" << endl;
		cin >> tall;
		sum = sum + tall;
	} while (tall != 0);

	cout << "Summen av tallene er: " << sum << endl;
	return;
}

	//c)
	/* Jeg brukte en for-løkke i a) og en do-while i b)
	(kunne også brukt en vanlig while-løkke). Bruker for 
	i a) fordi brukeren skal avklare kjørelengde på forhånd, 
	mens while i b) fordi det skal avklarer underveis. 
	*/

	//d)
double inputDouble(){
	cout << "Skriv inn et tall: ";
	double x{0};
	cin >> x;
	return x;
}

	//e)
/*void convertNokToEuro(){
	int amountNok{0};
	do {
		amountNok = inputDouble();
		double rate{9.75};
	} while (amountNok < 0);
	cout << amountNok * rate; //Why is rate not recognized?
	return;
	//unfinished! Checko out README. 
}
*/

	//f)
	/*Bør bruke inputDouble ()fordi jeg vil ha double som input i
	convertNokToEuro(). Velger void uten returverdi, fordi jeg tolker
	det som at man skal printe til skjerm med en gang, i stedet
	for å returnere, for deretter å printe i main(). 
	*/

//Task 2 ends here. 

//Task 3b, gangetabell: Use setw in the book to make nice tables.

void multipTable(){
	int width{0};
	int height{0};
	cout << "Skriv inn ønsket bredde: " << endl;
	cin >> width;
	cout << "Skriv inn ønsket høyde: " << endl;
	cin >> height;
	//Now i need to write out the multiplication table!

	return;
}

//Task 4
/*
	//a)
double discriminant(double a, double b, double c){
	return pow(b,2) - 4*a*c;
}
	//b)
void printRealRoots(double a, double b, double c){
	//use a function from std-library to find the root. See Appendix B. B.9.2 is useful. 
	double x1 = (-b + std::sqrt(discriminant(a,b,c)))/static_cast<double>(2*a);
	double x2 = (-b - std::sqrt(discriminant(a,b,c)))/static_cast<double>(2*a);
	//hopefully this will work. Just tested with std::sqrt without checking the book. 

	return;
}
	//c)
void solveQuadraticEquation(){
	cout << "Skriv inn 3 desimaltall i følgende format: \"a b c\"" << endl;
	double a{0};
	double b{0};
	double c{0};
	cin >> a >> b >> c; //Hopefully this works. 
	printRealRoots(a,b,c);
}

	//d) Add solveQuadraticEquation() to the menu-list in main(). 

	//e) More with the test-menu.
*/
//Task 4 ends here. 

//Task 5, Grafikk - Pythagoras' læresetning. 

//Useful graphic-theory in 12.2 - 12.3. 

void pythagoras(){
	using namespace Graph_lib;
	Point tl{100,100};
	Simple_window win{tl, 600, 600, "Pythagoras"};
	
	Polygon rightTriangle;
	rightTriangle.add(Point{350,200});
	rightTriangle.add(Point{150,200});
	rightTriangle.add(Point{350,350});
	rightTriangle.set_fill_color(Color::red);

	Polygon smallestSquare;
	smallestSquare.add(Point{350,200});
	smallestSquare.add(Point{350,350});
	smallestSquare.add(Point{500,350});
	smallestSquare.add(Point{500,200});
	smallestSquare.set_fill_color(Color::blue);

	Polygon biggestSquare;
	biggestSquare.add(Point{350,350});
	biggestSquare.add(Point{200, 550});
	biggestSquare.add(Point{0,400});
	biggestSquare.add(Point{150,200});
	biggestSquare.set_fill_color(Color::black);

	Polygon mediumSquare;
	mediumSquare.add(Point{150,200});
	mediumSquare.add(Point{350,200});
	mediumSquare.add(Point{350,0});
	mediumSquare.add(Point{150,0});
	mediumSquare.set_fill_color(Color::magenta);
	
	win.attach(rightTriangle);
	win.attach(smallestSquare);
	win.attach(biggestSquare);
	win.attach(mediumSquare);
	win.wait_for_button();
}

//Task 5 ends here. 

//Task 6; Lån med bruk av løkker: 

	//a)

int main(){
	/*
	//Task 3, Menysystem:
	
	int userChoice{0};
	do {
		cout << "Velg funksjon: " << endl;
		cout << "0) Avslutt " << endl;
		cout << "1) Summer et bestemt antall tall " << endl;
		cout << "2) Summer flere tall, helt til du avslutter " << endl; 
		cout << "3) Konverter NOK til EURO " << endl; 
		cout << "4) Skriv ut gangetabell i ønsket format " << endl;
		cout << "Angi valg (0-4) " << endl; 
		cin >> userChoice;
		switch(userChoice){
			case 1: 
				readAndWriteSumOfIntegers();
				break;
			case 2: 
				readAndSumIntegersWhile();
				break;
			case 3: //Cannot be finished because of task 2, but the method works so far!
				convertNokToEuro();
				break;
			*/
			/*
			case 4:
				multipTable();
				break;
			
			default: 
				cout << "Du må velge ett av tallene som finnes i menyen!";
				break;
		}
	} while (userChoice != 0);
	*/
	pythagoras();

	return 0; 

}
