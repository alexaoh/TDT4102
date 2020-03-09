#include "iostream"
#include "utility" //Har std::swap ifølge oppgaveteksten
#include "iomanip"

using namespace std;

class Matrix{
    int rows; 
    int columns;
    double** table; //Want to make an array of pointers to other arrays. 

public:
    Matrix();
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    bool isValid() const;
    double operator[](int i);
    friend ostream& operator<<(std::ostream& os, Matrix& m);
};
