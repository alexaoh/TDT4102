#include "std_lib_facilities.h"
#include "CardDeck.h"

class Blackjack{
private: 

public: 
    int getWinner() const; //User wins by 3 different methods. 
    
};

//Where should i place the wishes to draw more cards?
class Dealer{
private: 
    vector<Card> cards;

public:
    Dealer(); //Sets the dealers cards somehow
    vector<Card> getCards() const; //better to print perhaps?
    int getTotalPoints() const;
    
};

class Player{
private:
    vector<Card> cards;
public: 
    Player(); //Sets the players cards somehow
    vector<Card> getCards() const;
    int getTotalPoints() const;

};

class PointsPerCard{
    //Maybe practical to define the points of the cards here?
};