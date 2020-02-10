#include "std_lib_facilities.h"
#include "Blackjack.h"

int main()
{
	Suit s = Suit::spades;
	Rank r = Rank::ace;
	string heisann{suitToString(s)};
	string heisann2{rankToString(r)};

	cout << "Dette er suitToString(): " << heisann << " " << "RankToString(): " << heisann2 << endl;
	cout << "Test the functions: " << endl;

	Card nyttKort{s,r};
	cout << "getSuit() " << suitToString(nyttKort.getSuit()) << endl;
	cout << "getRank() " << rankToString(nyttKort.getRank()) << endl;
	cout << "toString() " << nyttKort.toString() << endl;
	cout << "toStringShort() " << nyttKort.toStringShort() << endl;

	CardDeck newDeck{};
	newDeck.print();
	newDeck.shuffle();
	cout << endl;
	cout << "Shuffling the deck" << endl; 
	newDeck.printShort();

	cout << "The last card is: " << newDeck.drawCard().toString() << endl;
	cout << "New deck after drawing last card: " << endl;
	newDeck.printShort();

	bool playMore{true};
	int answer{2};
	while (playMore == true){
		cout << "Begin a new game of Blackjack: " << endl;
		Blackjack newGame;
		newGame.printRules();
		newGame.printGame();
		newGame.getGameWinner(newGame);
		cout << endl; 
		cout << "Du you want to play again? (1 = Yes/ 2 = No)" << endl; 
		cin >> answer;
		while (cin.fail()){
			cin.clear();
			cout << "Not an integer 1 or 2, please try again!" << endl;
			for (char c; (cin >> c) && !isdigit(c); ){}
			cin.unget();
		}
		if (answer == 2){
			playMore = false;
		} else if (answer == 1){
			playMore = true;
		} else{
			cout << "Not a valid input, please try again.";
			continue; //have not fixed invalid integer inputs here yet, but cannot be bother right now!
		}
	}
	

	/*Task 1e Teori: 
	Fordeler ved å bruke symboler kontra heltall og strenger i koden: 
	1. Enklere å forstå hvilke symboler som symboliserer hvilke størrelser, 
	vs det å måtte holde styr på hvilke heltall som hører til hvilke strenger f.eks. 
	2. Blir enklere for andre å forstå koden, da symbolene er tydeligere enn 
	egendefinerte heltall og strenger som hører sammen. Med mindre det finnes en slags
	globalt anerkjent "best practice" for slike definisjoner, kan det være vanskelig 
	å sette seg inn i noen andre sin kode pga dette. 
	*/
	keep_window_open();
}
