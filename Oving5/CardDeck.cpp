#include "std_lib_facilities.h"
#include "CardDeck.h"

CardDeck::CardDeck(){
    //Does not work as it should!
    /*
    int size{52};
    for (int SuitInt = static_cast<int>(Suit::clubs); SuitInt != static_cast<int>(Suit::spades); SuitInt++){
        for (int RankInt = static_cast<int>(Rank::two); RankInt != static_cast<int>(Rank::ace); RankInt++){
            Card nyttKort{static_cast<Suit>(SuitInt), static_cast<Rank>(RankInt)};
            cards[RankInt-2] = nyttKort.toStringShort();
        }
    }
    */
   //Tried this instead
    for (int i = 0; i < 4; i++){
        for (int j = 2; j <= 13 + 1; j++){
            cards.push_back(Card{Suit(i), Rank(j)});
        }
    }
    
}

void CardDeck::swap(int card1, int card2){
    Card dummy{cards[card2]};
    cards[card2] = cards[card1];
    cards[card1] = dummy;
    return;
}

void CardDeck::print() const{
    for (auto card : cards){
        cout << card.toString() << endl;
    }

    return;
}

void CardDeck::printShort() const{
    for (auto card : cards){
        cout << card.toStringShort() << endl;
    }

    return;
}

void CardDeck::shuffle(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int length = cards.size();
    int halfLength = length/2;
    for (unsigned int i = 0; i<halfLength; i++){
        int random_number1 = rand() % length;
        int random_number2 = rand() % length;
        swap(random_number1, random_number2);
    }
}

const Card CardDeck::drawCard(){
    Card card{cards[cards.size()-1]};
    cards.erase(cards.end()-1); //This does not work with regular index. Why?! Iterator? 
    return card;
}

