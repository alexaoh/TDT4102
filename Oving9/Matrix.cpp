#include "iostream"
#include "Matrix.h"

using namespace std;

Matrix::Matrix(){
    double **table = nullptr;

}

Matrix::Matrix(int nRows, int nColumns):rows{nRows}, columns{nColumns}{
    //Prøvde å lage en tabell med pointers. 

    double** table = new double*[rows];
    for (int i = 0; i<rows; i++){
        double *col = new double[columns];
        table[i] = col; 
    } 

    for (int i = 0; i<rows; i++){
        for (int e = 0; e < columns; e++){
            table[i][e] = 0;
        }
    }
}

Matrix::Matrix(int nRows):Matrix{nRows, nRows}{
    for (int i = 0; i<rows; i++){
        for (int e = 0; e < columns; e++){
            if (i = e) table[i][e] = 1;
        }
    }
}

double Matrix::get(int row, int col) const {
    return table[row][col];
}

void Matrix::set(int row, int col, double value){
    table[row][col] = value;
}

bool Matrix::isValid() const {
    if (table == nullptr){
        return false;
    }
    else{
        return true;
    }
}

double Matrix::operator[](int i){
    //hvordan overlaste slik at den fungerer for table[][] (to indekser?)
}
