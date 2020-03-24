#include "LinkedList.h"

std::ostream & operator<<(std::ostream & os, const LinkedList::Node& node){
    os << node.getValue(); //Why use friend when I am denied access to private variables anyway?
    return os;
}


LinkedList::Node* LinkedList::LinkedList::insert(Node *pos, const std::string& value){
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
    pos->prev->next = std::move(newNode); //Moves ownership of the new Node unique_pointer to the previous node. 
    pos->prev = std::move(newNode->getNext()); //Skjønner ikke denne!?!?!? Burde den ikke vært motsatt? Slik a new node eier pos sin unique_pointer? Eller er det nettopp dette den sier nå?
    return newNode.get();
}


LinkedList::Node* LinkedList::LinkedList::remove(Node* pos){ //no range-checking here. 
    delete pos;
    return pos->getNext(); //Kan være at denne er inaccessible, siden pos slettes først! Men se an når det testes om det fungerer
}

LinkedList::Node* LinkedList::LinkedList::find(const std::string& value){ 
    for (Node* it = this->begin(); it != this->end(); ++it){
        if (it->getValue() == value){
            return it; 
        }
    }    
    return this->end(); 
}

void LinkedList::LinkedList::remove(const std::string& value){
    Node* valueFound = find(value);
    if (valueFound != this->end()){
        delete valueFound;
    }
}

std::ostream& operator<<(std::ostream& os, const LinkedList::LinkedList& list){
    for (LinkedList::Node* it = list.begin(); it != list.end(); ++it){
        if (it->getNext() == list.end()){
            os << it->getValue();
        } else (os << it->getValue() << ", ");
    }
    return os;
}
