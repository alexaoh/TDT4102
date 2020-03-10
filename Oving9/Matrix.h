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
    Matrix(const Matrix& rhs); //Copy constructor
    Matrix& operator=(const Matrix& rhs); //Copy assignment constructor
    //Matrix& operator=(Matrix rhs); //Copy assignment with copy-and-swap --> Only works with same-dimensional-matrices!
    explicit Matrix(int nRows);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    bool isValid() const;
    double* operator[](int i);
    friend ostream& operator<<(ostream& os, const Matrix& m);
    Matrix& operator+=(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);
};
