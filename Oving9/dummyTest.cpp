#include "dummyTest.h"
#include "iostream"
using namespace std;

Dummy::Dummy(const Dummy& d):num{nullptr}{
    this->num = new int{};
    *num = *d.num;
}

Dummy& Dummy::operator=(const Dummy& d){
    int *newNum{ new int{*d.num}};
    delete num;
    num = newNum;
    return *this;
}

void dummyTest(){
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    cin.get();
}
