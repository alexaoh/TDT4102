#include "Matrix.h"


//using namespace std;

Matrix::Matrix(){
    table = nullptr;

}

Matrix::Matrix(int nRows, int nColumns):rows{nRows}, columns{nColumns}{
    //Define the matrix (array of pointers to other arrays)
    table = new double*[rows]; 

    for (int i = 0; i < rows; ++i){
        table[i] = new double[columns];
    }
    
    //Populate the matrix
    for (int i = 0; i<rows; i++){
        for (int e = 0; e < columns; e++){
            table[i][e] = 0.0;
        }
    }
}

Matrix::Matrix(int nRows):Matrix{nRows, nRows}{
    for (int i = 0; i<rows; i++){
        for (int e = 0; e < columns; e++){
            if (i == e) table[i][e] = 1.0;
        }
    }
}

Matrix::~Matrix(){
    delete[] table; //er nok ikke så enkelt som dette da muligens!? Prøver derimot med dette først
    table = nullptr;

    //https://stackoverflow.com/questions/16001803/pointer-to-pointer-dynamic-two-dimensional-array

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
    return *table[i]; //Denne må fikses!
}

ostream& operator<<(ostream& os, Matrix& m){
    int rows{m.rows};
    int columns{m.columns};
    if (rows == 0 || columns == 0) throw runtime_error("Invalid matrix"); //These can be caught later if needed. 
    if (m.isValid() == false) throw runtime_error("Invalid matrix");
    os << "[" << endl;
    for (int i = 0; i < rows; ++i){
        os << "[";
        for (int e = 0; e < columns; ++e){
            os << setw(3) << m.table[i][e] << " ";
        }
        os << "]" << endl;
    }
    os << "]";
    return os;
}
