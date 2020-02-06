#include "std_lib_facilities.h"
#include "CardDeck.h"

//Prøver å kun bruke Blackjack-klassen først!
class Blackjack{
private: 
    vector<Card> dealerCards;
    vector<Card> playerCards;
    string winner;
    void printShortDealerCards() const;
    void printShortPlayerCards() const;
public: 
    Blackjack();
    void printRules() const;
    string getWinner() const { return winner; }
    //vector<Card> getDealerCards() const { return dealerCards; }
    //Card getFirstDealerCard() const { return dealerCards[0] }
    vector<Card> getPlayerCards() const { return playerCards; }
    
    void printGame() const;
    
};

class DealCardDecks{
private: 
    vector<CardDeck> cardDecks;
public: 
    DealCardDecks();
    vector<CardDeck> getDealtCards(){ return cardDecks; }


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
