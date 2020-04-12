#include "Task4.h"

Dataset::Dataset(int N): y{new double[N]}, N{N}{
    for (int i = 0; i < N; ++i){
        y[i] = 0.0;
    }
}

Dataset::Dataset(const Dataset& other): y{new double[other.N]}, N{other.N}{
    for (int i = 0; i<N; ++i){
        y[i] = other.y[i];
    }
}

Dataset::~Dataset(){
    delete[] y;
}

Dataset& Dataset::operator=(Dataset rhs){
    std::swap(y, rhs.y);
    std::swap(N,rhs.N);
    return *this;
}

double Dataset::interpolate(double x){
    int x0 = floor(x);
    int x1 = x0 + 1;
    if (x>N-1) return y[N-1];
    if (x<0) return y[0];
    int y0 = y[x0];
    int y1 = y[x1];
    return static_cast<double>(y0 + (y1-y0)*(x-x0)/(x1-x0));
}

Dataset* random_data(double min, double max, int size){
    Dataset* d = new Dataset{size};
    for (int i = 0; i<size; ++i){
        double randomNum = rand();
        randomNum = (max-min)*randomNum/RAND_MAX + min;   
        (*d)[i] = randomNum;
    }
    return d;
}
