#include "std_lib_facilities.h"
#include "Blackjack.h"

Blackjack::Blackjack(){
    CardDeck deck;
    deckInUse = deck;
    deckInUse.shuffle();
    for (int i = 0; i < 4; i++){
        if (i % 2 == 0){
            playerCards.push_back(deckInUse.drawCard());
        }else{
            dealerCards.push_back(deckInUse.drawCard());
        }
    }

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


void Blackjack::printGame(){
    bool check{true};
    while (moreGame == true){
        if (check == true){
            PointsInCardVector player(playerCards);
            playerPoints = player.getPointsInCardDeck();

            PointsInCardVector dealer(dealerCards);
            dealerPoints = dealer.getPointsInCardDeck();

            cout << "These are your cards: " << endl;
            printShortPlayerCards();
            cout << "Testing: " << endl; 
            printShortDealerCards(); 
            cout << endl;
            cout << "The dealer's first card is: " << endl;
            cout << dealerCards[0].toStringShort();
            cout << endl; 
            cout << "The scores are: " << endl;
            cout << "Player: " << playerPoints << endl;
            cout << "Dealer: " << dealerPoints << endl; 
            checkWinner();
            if (moreGame == false){
                break;
            }
        }

        cout << "Do you want to draw another card? (1 = Y/2 = N)" << endl; 
        cin >> answer;
        while (cin.fail()){
            cin.clear();
            cout << "Not an integer: 1 or 2, please try again \n";
            for (char c; (cin >> c) && !isdigit(c); ){}
            cin.unget();
        }
        if (cin) {
            if (answer == 1){
                playerCards.push_back(deckInUse.drawCard());
                randomDrawDealerCard();
                check = true;
            }else if (answer == 2){ 
                checkWinner();
                randomDrawDealerCard();
                check = true;
            } else{
                cout << "Pleae give a valid input: either 1 or 2. " << endl; 
                check = false;
                continue;
            }
        }
    }
    return;

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

void Blackjack::checkWinner(){
    if (playerPoints == 21 && dealerPoints != 21){
        moreGame = false;
        winner = "Player won!";
    } else if (playerPoints < 21 && (playerPoints > dealerPoints && dealerPoints > 21)){
        moreGame = false;
        winner = "Player won!";
    } else if (dealerPoints > 21 && playerPoints <= 21){
        moreGame = false;
        winner = "Player won!";
    }  else if (dealerPoints < 21 && playerPoints < 21){
        moreGame = true;
    } else{
        moreGame = false;
        winner = "Dealer won!";
    }
    return;
}

void Blackjack::getGameWinner(Blackjack& newGame) const{
    if (newGame.moreGame == false){
		cout << newGame.winner << endl;
	}
    return;
} 

void Blackjack::randomDrawDealerCard(){
    if (dealerPoints < 17){
        //makes it random if dealer draws a new card. (in theory a 50/50 chance) 
        srand(static_cast<unsigned int>(time(nullptr))); 
        int randomNumber = rand() % 2;
        if (randomNumber == 0){
            dealerCards.push_back(deckInUse.drawCard());
        }
    }
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
