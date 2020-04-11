#include <iostream>

class Dataset{
    double* y;
    int N;
public: 
    Dataset(int N);
    Dataset(const Dataset& other);
    ~Dataset();
    Dataset& operator=(Dataset rhs);
    double interpolate(double x);
    int getSize() const { return N; }
    double& operator[](int i) { return y[i]; }
}
