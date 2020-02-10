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
    int answer{2};
    void randomDrawDealerCard();
public: 
    Blackjack();
    void printRules() const;
    void getGameWinner(Blackjack& newGame) const;
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
