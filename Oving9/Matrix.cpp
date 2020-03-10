#include "Matrix.h"


//using namespace std;

Matrix::Matrix(){
    table = nullptr;
}

Matrix::Matrix(int nRows, int nColumns):rows{nRows}, columns{nColumns}{
    //Define the matrix (array of pointers to other arrays)
    table = new double*[rows]; 

    for (int i = 0; i < rows; ++i){
        table[i] = new double[columns]{0.0}; //This populates the entire matrix with zeros
    } //=> The loop below is completely unnecessary!
    /*
    //Populate the matrix
    for (int i = 0; i<rows; i++){
        for (int e = 0; e < columns; e++){
            table[i][e] = 0.0;
        }
    }
    */
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
    
    for (int i = 0; i < rowsRhs; ++i){
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

Matrix& Matrix::operator+=(const Matrix& rhs){
    if (rows != rhs.rows || columns != rhs.columns){
        table = nullptr;
        return *this; //This is an invalid matrix because of earlier nullptr functionality
    }
    for (int i = 0; i < rows; ++i){
        for (int e = 0; e < columns; ++e){
            table[i][e] += rhs.table[i][e];
        }
    }
    return *this;
}
   
Matrix Matrix::operator+(const Matrix& rhs){
    Matrix A{*this};
    A += rhs; //Automatically checks if dimensions are correct because of += operator. 
    return A;

    
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

double* Matrix::operator[](int i){
    return table[i];   
}

ostream& operator<<(ostream& os,const Matrix& m){
    int rows{m.rows};
    int columns{m.columns};
    if (rows <= 0 || columns <= 0) throw logic_error("Invalid matrix"); //These can be caught later if needed. 
    if (m.isValid() == false) throw logic_error("Invalid matrix");
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
