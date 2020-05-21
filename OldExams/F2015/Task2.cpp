#include "Task2.h"

RowNode::RowNode(int size):arr{ new int[size]}, 
next{nullptr}, prev{nullptr}, size{size}{}

RowNode::~RowNode(){
    delete[] arr;
}

DynamicMultiArray::DynamicMultiArray():first{nullptr}, last{nullptr}{}

void DynamicMultiArray::add(int size){
    RowNode* node = new RowNode{size};
    node->prev = last;
    last = node;
    if (first == nullptr){
        first = node;
    } else {
        last->prev->next = last;
    }
}

void DynamicMultiArray::remove(int row){
    //Må først finne hva index (dvs noden til den oppgitte raden) er:
    if (first == nullptr) throw std::invalid_argument("Empty list!");
    RowNode* current = first;
    for (int i = 0; i < row; ++i){
        current = current->next;
        if (current == nullptr) throw std::invalid_argument("Row does not exist");
    } //Har generalisert dette til en funksjon lenger ned. Burde brukt her også-  

    if (current == first){ 
        first = current->next;
    }
    if (current == last){
        last = last->prev;
    }
    if (current->prev != nullptr){
        current->prev->next = current->next;
    }
    if (current->next != nullptr){
        current->next->prev = current->prev;
    }
    delete current;

}



int DynamicMultiArray::get(int row, int column){
    RowNode* found = findNode(row);
    if (column > found->size) std::invalid_argument("This column does not exist");
    return found->arr[column];
}

void DynamicMultiArray::set(int row, int column, int val){
    RowNode* found = findNode(row);
    if (column > found->size) std::invalid_argument("This column does not exist");
    found->arr[column] = val;
}

RowNode* DynamicMultiArray::findNode(int row){
    if (first == nullptr) std::invalid_argument("Empty list");
    RowNode* current = first;
    for (int r = 0; r < row; ++r){
        current = current->next;
        if (current == nullptr) std::invalid_argument("This row does not exist");
    }
    return current;
}

DynamicMultiArray::~DynamicMultiArray(){
    while (first != nullptr){
        RowNode* copy = first;
        first = first->next;
        delete copy;
    }
}

//Task 3 is a continuation of task 2!

void RowNode::resize(int increase){
    int* array = new int[size+increase];
    std::copy(arr, arr+size, array);
    delete[] arr;
    arr = array;
}

DynamicMultiArray::DynamicMultiArray(const DynamicMultiArray& old):DynamicMultiArray(){
    RowNode* current = old.first;
    while(current != nullptr){
        //Benytter med av copy constructor til RowNode.
        RowNode* newRow = new RowNode{*current};
        newRow->prev = last;
        last = newRow;
        if (first == nullptr){
            first = newRow;
        } else {
            last->prev->next = last;
        }
        current = current->next;
    }
}

DynamicMultiArray& DynamicMultiArray::operator=(DynamicMultiArray old){
    std::swap(first, old.first);
    std::swap(last, old.last);
    return *this;
}

RowNode::RowNode(const RowNode& old):RowNode(old.size){
    std::copy(old.arr, old.arr + size, arr);
}
