#include <iostream>
#include <utility>

using namespace std;

class ValArr{
    int* data;
    int size;
public: 
    ValArr(int size);
    ValArr(const ValArr& org);
    ValArr& operator=(ValArr rhs);
    int& operator[](int i);
    int getSize();
    ~ValArr();
};

class RefArr{
    int* data;
    int* size;
    int* use; 
public: 
    RefArr(int size);
    RefArr(const RefArr& org);
    RefArr& operator=(const RefArr& rhs);
    int& operator[](int i);
    int getSize();
    ~RefArr();
};
