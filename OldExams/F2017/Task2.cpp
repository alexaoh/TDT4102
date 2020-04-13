#include "Task2.h"

Array2D::Array2D(int xdim, int ydim, float fill=0.0):xdim{xdim}, ydim{ydim}, data{new float[xdim*ydim]}{
    for (int i = 0; i<size(); ++i){
        data[i] = fill;
    }
}

Array2D::Array2D(const Array2D& other):xdim{other.xdim}, ydim{other.ydim}, data{new float[xdim*ydim]}{
    for (int i = 0; i<size(); ++i){
        data[i] = other.data[i];
    }
}

Array2D::~Array2D(){
    delete[] data;
}   

Array2D& Array2D::operator=(Array2D rhs){
    float* array = new float[rhs.xdim*rhs.ydim];
    for (int i = 0; i < rhs.size(); ++i){
        array[i] = rhs.data[i];
    }
    delete[] data;
    data = array;
    xdim = rhs.xdim;
    ydim = rhs.ydim;
    return *this;
    //kunne også brukt swap() fra <algorithm>, som er en mye enklere løsning!
}

float* Array2D::operator[](int i){
    return &data[xdim*i];
}

float Array2D::min(){
    float min{data[0]};
    for (int i = 0; i < size(); ++i){
        if (data[i]<min) min = data[i];
    }
    return min;
}

float Array2D::max(){
    float max{data[0]};
    for (int i = 0; i < size(); ++i){
        if (data[i]>=max) max = data[i];
    }
    return max;
}

std::ostream& Array2D::operator<<(std::ostream& os){
    //De mente egt at den skulle lages uten å være en medlemsfunksjon, men det blir nesten helt likt. 
    for (int y = 0; y < ydim; ++y){
        for (int x = 0; x < xdim; ++x){
            os << this[y][x] << " ";
        }
        os << std::endl;
    }
}   
