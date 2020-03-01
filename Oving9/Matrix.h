class Matrix{
    int rows; 
    int columns;

public:
    Matrix();
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix(){ delete[] this; } //Vet ikke om dette fungerer
};
