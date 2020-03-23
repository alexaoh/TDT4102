#include "LinkedList.h"

using namespace LinkedList;
using namespace std;

ostream & operator<<(ostream & os, const Node& node){
    os << node.getValue(); //Why use friend when I am denied access to private variables anyway?
    return os;
}

/*
Node* insert(Node *pos, const std::string& value){
    
    unique_ptr<Node> uniquePos = make_unique<Node>(pos->getValue(), pos->getNext(), newNode*); //Try to use the default constructor to make a new node. 
    Node newNode{value, uniquePos, pos->getPrev()};
    //Dette går ikke! Den ene må jo nesten instansieres først! Hvordan? De er gjensidig avhengige av hverandre?!
}
*/

Node* remove(Node* pos){
    
}
