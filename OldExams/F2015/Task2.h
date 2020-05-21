#include <iostream>
#include <stdexcept>  
#include <map>  
#include <algorithm>

class RowNode{
    int* arr;
    RowNode* next; 
    RowNode* prev;
    int size;
    RowNode(const RowNode& old); //Copy constructor
    RowNode& operator=(const RowNode& old); //Copy assignment. 
public:     
    RowNode(int size);
    ~RowNode(); 
    friend class DynamicMultiArray;
    void resize(int increase);
};

class DynamicMultiArray{
    RowNode* first;
    RowNode* last;
public: 
    DynamicMultiArray();
    DynamicMultiArray(const DynamicMultiArray& old); //Copy constructor
    DynamicMultiArray& operator=(DynamicMultiArray old); //Copy assignment
    ~DynamicMultiArray();
    void add(int size);
    void remove(int row);
    int get(int row, int column);
    void set(int row, int column, int val);
    RowNode* findNode(int row); //Utility for get and set.
};


