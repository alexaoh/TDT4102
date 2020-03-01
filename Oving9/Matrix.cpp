#include "iostream"
#include "Matrix.h"

Matrix::Matrix(){
    double *table = nullptr;

}

Matrix::Matrix(int nRows, int nColumns):rows{nRows}, columns{nColumns}{
    //Prøvde å lage en tabell med pointers. 
    double **table = new double*[nColumns];
    for (int i = 0; i<nColumns; i++){
        double *row = new double[nRows];
        table[i] = row; 
    } //Må fortsatt fylle inn med nuller!

}

Matrix::Matrix(int nRows):Matrix(nRows, nRows){
    //lag identitetsmatrisa!
}
