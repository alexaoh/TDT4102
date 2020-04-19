#include <iostream>

template<typename T>
class Rational{
    T n; 
    T d; 
    void reduce();
    int gcd(int a, int b);
public: 
    Rational(); 
    Rational(T n, T d);
    T numerator();
    T denominator();
    double to_double();
    bool operator<(Rational& rhs);
    bool operator==(Rational& rhs);
    Rational operator++(int i);
    Rational operator*(const Rational& rhs);
    Rational operator*=(const Rational& rhs);
    static int gcd(int a, int b); //Hvis den vil brukes slik som de sier i j)
};
