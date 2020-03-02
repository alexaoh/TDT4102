class Matrix{
    int rows; 
    int columns;
    double** table; //prøve med en vektor i stedet?

public:
    Matrix();
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix(){ delete[] this; } //Vet ikke om dette fungerer
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    bool isValid() const;
    double operator[](int i);
};
