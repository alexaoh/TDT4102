#include "std_lib_facilities.h"
#include "Card.h"

string suitToString(Suit s){
    map<Suit, string> suitStrings;
    suitStrings[Suit::clubs] = "Clubs";
    suitStrings[Suit::diamonds] = "Diamonds";
    suitStrings[Suit::hearts] = "Hearts";
    suitStrings[Suit::spades] = "Spades";
    return suitStrings[s];
}

string rankToString(Rank r){
    map<Rank, string> rankStrings;
    rankStrings[Rank::two] = "Two";
    rankStrings[Rank::three] = "Three";
    rankStrings[Rank::four] = "Four";
    rankStrings[Rank::five] = "Five";
    rankStrings[Rank::six] = "Six";
    rankStrings[Rank::seven] = "Seven";
    rankStrings[Rank::eight] = "Eight";
    rankStrings[Rank::nine] = "Nine";
    rankStrings[Rank::ten] = "Ten";
    rankStrings[Rank::jack] = "Jack";
    rankStrings[Rank::queen] = "Queen";
    rankStrings[Rank::king] = "King";
    rankStrings[Rank::ace] = "Ace";
    return rankStrings[r];
}

Card::Card(Suit suit, Rank rank)
:s{suit}, r{rank}{}

Suit Card::getSuit() const{
    return s; 
}

Rank Card::getRank() const{
    return r;
}

string Card::toString() const{
    string totalString{rankToString(r) + " of " + suitToString(s)};
    return totalString;
}

string Card::toStringShort() const{
    string suit = suitToString(s);
    string shortString;
    shortString += suit[0];
    shortString += to_string(static_cast<int>(r));
    return shortString; 
}
