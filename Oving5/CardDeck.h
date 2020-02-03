#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck{
private:
    vector<Card> cards;
    void swap(int card1, int card2); 
    //I made swap() private because it is only used (so far)
    //by shuffle(). No one "on the outside" needs to use it (so far). 
public:
    CardDeck(); 
    void print() const;
    void printShort() const;
    void shuffle();
    const Card drawCard();
};
