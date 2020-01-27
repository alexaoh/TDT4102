#include "std_lib_facilities.h"
#include "Card.h"

string suitToString(Suit s){
    map<Suit, string> suitStrings;
    suitStrings[Suit::clubs] = "Clubs";
    suitStrings[Suit::diamonds] = "Diamons";
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
:s{suit}, r{rank}
{
}

string Card::getSuit(){
    string suit = suitToString(s);//Return the true Suit from enum instead of the string-representation of it?
    return suit; 
}

string Card::getRank(){
    string rank = rankToString(r); //should try to return a number here instead
                                    //Will make it easier in toStringShort()!
                                    //This is probably a hint given from "Nyttig å vite as well!"
    return rank;
}

string Card::toString(){
    string suit = Card::getSuit();
    string rank = Card::getRank();
    string totalString{suit + " of " + rank};
    return totalString;
}

string Card::toStringShort(){
    string totalString = Card::toString();
    string shortString;
    shortString += totalString[0];
    //Need to add the number-value to shortString aswell!
    //Check comments further up in the code. 
}
