#include "Task3.h"

int& ValArr::operator[](int i){
    return data[i];
}

int ValArr::getSize(){
    return size;
}

int& RefArr::operator[](int i){
    return data[i];
}

int RefArr::getSize(){
    return *size;
}

ValArr::ValArr(int size):data{new int[size]}, size{size}{}

ValArr::ValArr(const ValArr& org):ValArr(org.size){
    copy(org.data, org.data+org.size, data);
}   

ValArr::~ValArr(){
    delete[] data;
}

ValArr& ValArr::operator=(ValArr rhs){
    swap(data, rhs.data);
    swap(size, rhs.size);
    return *this;
}

RefArr::RefArr(int size):data{new int[size]}, size{new int(size)}, use{new int(1)}{}

RefArr::RefArr(const RefArr& org){
    data = org.data; //shallow copy on purpose.
    size = org.size;
    use = org.use;
    *use++;
}

RefArr::~RefArr(){
    if (!(--*use)){//Denne blir true når use == 0
        delete[] data;
        delete size;
        delete use;
    }
}

RefArr& RefArr::operator=(const RefArr& rhs){
    ++*rhs.use;
    if (!(--*use)){//Denne blir true når use == 0
        delete[] data;
        delete size;
        delete use;
    }
    data = rhs.data;
    size = rhs.data;
    use = rhs.use;
    return *this;
}
