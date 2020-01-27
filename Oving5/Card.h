#include "std_lib_facilities.h"
enum class Suit{
    clubs, diamonds, hearts, spades
};

enum class Rank{
    two=2, three, four, five, six, seven, eight, nine, ten,
    jack, queen, king, ace
};

string suitToString(Suit s);
string rankToString(Rank r);

class Card{
private: 
    Suit s;
    Rank r;
public: 
    Card(Suit suit, Rank rank);
    string getSuit();
    string getRank();
    string toString();
    string toStringShort();
};
