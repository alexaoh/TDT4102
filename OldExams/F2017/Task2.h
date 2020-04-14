#include <iostream>
#pragma once

class Array2D{
    int xdim;
    int ydim;
    float* data;
public: 
    Array2D(int xdim, int ydim, float fill=0.0);
    Array2D(const Array2D& other);
    ~Array2D();
    Array2D& operator=(Array2D rhs);

    unsigned int getXdim() const { return xdim; }
    unsigned int getYdim() const { return ydim; }
    int size() { return xdim * ydim; }

    float* operator[](int i);
    std::ostream& operator<<(std::ostream& os);

    float min();
    float max(); 
};
