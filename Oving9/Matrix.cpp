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

Matrix::Matrix(const Matrix& rhs):rows{rhs.rows}, columns{rhs.columns}{
    //Define the matrix table
    table = new double*[rows]; 
    
    for (int i = 0; i < rows; ++i){
        table[i] = new double[columns]; //This-pointere trengs altså ikke foran table[i] her eller lenger nede. Fungerer like fint uten. 
    }
    //Populate the matrix table
    for (int i = 0; i < rows; ++i){
        for (int e = 0; e < columns; ++e){
            table[i][e] = *&rhs.table[i][e];
        }
    }
    
}

Matrix& Matrix::operator=(const Matrix& rhs){
    //Without copy-and-swap
    
    int rowsRhs = rhs.rows;
    int columnsRhs = rhs.columns;
    double **table1 = new double*[rowsRhs]; 
    
    for (int i = 0; i < rows; ++i){
        table1[i] = new double[columnsRhs]; 
    }

    for (int i = 0; i < rowsRhs; ++i){
        for (int e = 0; e < columnsRhs; ++e){
            table1[i][e] = *&rhs.table[i][e];
        }
    }

    for (int i = 0; i < rows; ++i){
        delete[] table[i];
    }
    delete[] table;

    table = table1;
    rows = rowsRhs;
    columns = columnsRhs;
    return *this;
}


/*
Matrix& Matrix::operator=(Matrix rhs){
    //With copy-and-swap --> works with same-dimensional matrices!
    swap(this->table, rhs.table);
    return *this;
}
*/

Matrix& Matrix::operator+=(Matrix& rhs){
    if (rows != rhs.rows || columns != rhs.columns){
        table = nullptr;
        Matrix invalid; //Fungerer når dimennsjonene er rett!
        return invalid; //Hvordan kan jeg returnere en ugyldig matrise som ikke blir lokal?
    }
    for (int i = 0; i < rows; ++i){
        for (int e = 0; e < columns; ++e){
            table[i][e] += rhs.table[i][e];
        }
    }
    return *this;
}
   
Matrix& Matrix::operator+(Matrix& rhs){
    *this += rhs; //Automatically checks if dimensions are correct (with the += operator functioning correctly)
    return *this; //klarer ikke uten å endre på det venstre objektet?!

    
}

Matrix::~Matrix(){
    for (int i = 0; i < rows; ++i){
        delete [] table[i]; 
    }
    delete[] table;
    table = nullptr;

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
