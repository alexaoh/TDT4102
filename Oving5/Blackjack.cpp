#include "std_lib_facilities.h"
#include "Blackjack.h"

Blackjack::Blackjack(){
    CardDeck deck;
    deck.shuffle();
    for (int i = 0; i < 4; i++){
        if (i % 2 == 0){
            playerCards.push_back(deck.drawCard());
        }else{
            dealerCards.push_back(deck.drawCard());
        }
    }
    PointsInCardVector player(playerCards);
    playerPoints = player.getPointsInCardDeck();

    PointsInCardVector dealer(dealerCards);
    dealerPoints = dealer.getPointsInCardDeck();
    

}


void Blackjack::printShortDealerCards() const{
    for (auto card : dealerCards){
        cout << card.toStringShort() << endl;
    }

    return;
}


void Blackjack::printShortPlayerCards() const{
    for (auto card : playerCards){
        cout << card.toStringShort() << endl;
    }

    return;
}


void Blackjack::printGame() const{
    cout << "These are your cards: " << endl;
    printShortPlayerCards();
    cout << "Testing: " << endl; 
    printShortDealerCards(); 
    cout << endl;
    cout << "The dealer has been delt the same amount of cards. His first card is: " << endl;
	cout << dealerCards[0].toStringShort();
	cout << endl; 
    char answer{'N'};
    cout << "The scores are: " << endl;
    cout << "Player: " << playerPoints << endl;
    cout << "Dealer: " << dealerPoints << endl; 
    cout << "Do you want to draw another card? (Y/N)" << endl; 
    cin >> answer;

    //Get input until it is a character! Fix later!
    if (answer == 'N'){
        //Check who wins
    } else{
        //Draw new card
    }
}

void Blackjack::printRules() const{
    cout << "The rules of the game!: " << endl 
         << "You are dealt two cards. " << endl
         << "The dealer is dealt the same amount of cards. " << endl
         << "One of the dealer's cards is for you to see, " << endl
         << "while the other is face down on the table" << endl
         << "you may choose to draw another card, or you may \"sit\"" << endl
         << "the player closest to 21 wins. ";
    return;
}

PointsInCardVector::PointsInCardVector(vector<Card> cards){
    for (int i = 0; i < cards.size(); i++){
        int cardValue = static_cast<int>(cards[i].getRank());
        if (cardValue > 10 && cardValue < 14){ 
            pointsInCardVector += pictureRank;
        } 
        else if (cardValue == 14){
            //Chooses if ace is 11 or 1 automatically
            if (pointsInCardVector > 10){
                pointsInCardVector += 1;
            } else pointsInCardVector += 11;
        }
        else if (cardValue <= 10){
            pointsInCardVector += cardValue;
        }
    }
}
