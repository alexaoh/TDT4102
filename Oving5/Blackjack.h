#include "std_lib_facilities.h"
#include "CardDeck.h"

class Blackjack{
private: 
    vector<Card> dealerCards;
    vector<Card> playerCards;
    CardDeck deckInUse;
    int dealerPoints{0};
    int playerPoints{0};
    string winner;
    bool moreGame{true};
    void printShortDealerCards() const;
    void printShortPlayerCards() const;
    void furtherPlay();
    void checkWinner();
    char answer{'N'};
    void randomDrawDealerCard();
public: 
    Blackjack();
    void printRules() const;
    void getGameWinner(Blackjack& newGame) const;
    //vector<Card> getDealerCards() const { return dealerCards; }
    //Card getFirstDealerCard() const { return dealerCards[0] }
    vector<Card> getPlayerCards() const { return playerCards; }
    void printGame();
    bool getMoreGame() const { return moreGame; }
    
};

class PointsInCardVector{
public: 
    PointsInCardVector(vector<Card> cards);
    int getPointsInCardDeck() const { return pointsInCardVector; } 
private: 
    int pointsInCardVector{0};
    int pictureRank{10};
};

/*

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
*/
