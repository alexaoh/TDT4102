#include "Task1.h"

//Dette vil ikke fungere som det skal! HELE KLASSEN må være i samme fil for at templating skal fungere som ønsket. 

//Se nederst her!: http://www.cplusplus.com/doc/oldtutorial/templates/

//Med mindre man bruker Explicit Template Instantiation! 

int Rational::gcd(int a, int b){
    if (b == a) return a;
    return gcd(b, a%b);
}


template<typename T>
void Rational<T>::reduce(){
    T common = gcd(n,d);
    n /= common;
    d /= common;
    if (d<0){
        n = -n;
        d = -d;
    }
}


template<typename T>
Rational<T>::Rational(T n, T d):n{n}, d{d}{
    reduce();
}


template<typename T>
double Rational<T>::to_double(){
    return n/static_cast<double>(d);
}


template<typename T>
bool Rational<T>::operator<(Rational& rhs){
    return to_double() < rhs.to_double();
}


template<typename T>
bool Rational<T>::operator==(Rational& rhs){
    return (!(*this < rhs) && !(rhs < *this));
}


template<typename T>
(Rational Rational<T>::operator++(int i)){
    Rational copy{*this}; 
    n += d;
    reduce();
    return copy;
}

template<typename T>
Rational Rational<T>::operator*=(const Rational& rhs){
    n *= rhs.n;
    d *= rhs.d;
    reduce();
    return *this;
}  


template<typename T>
Rational Rational<T>::operator*(const Rational& rhs){
    return *this *= rhs;
}

/* h) Ikke nødvendig å implementere assigment operator og/eller copy constructor,
    da de autogenererte gjør det vi ønsker; nemlig kopiere medlemsvariabler. Her har vi
    ikke noe dynamisk minne som må kopieres (deep copy),
*/
