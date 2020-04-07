#include "Task3.h"

double radian(double degree){
    return (degree/360.0)*2.0*PI;
}

double nFac(unsigned int n){
    double fac{1.0};
    if (n == 0) return 1.0; //Trenger egt ikke denne, men dgb. 
    else{
        for (unsigned int i = 2; i<=n; ++i){
            fac *= i;
        }
        return fac;
    }
}

double sineTaylorTerm(double x, int n){
    return (pow(-1.0, n)/nFac(2*n+1))*pow(x,2*n+1);
}

double sineTaylor(double x, int n){
    double sum{0};
    for (int i = 0; i<n;++i){
        sum += sineTaylorTerm(x, i);
    }
    return sum;
}

int testTaylor(double degree, double epsilon){
    int num{1};
    double radians = radian(degree); //antar at biblio-funksjonen sin også tar radianer, ikke grader.
    double sum{0};
    while (true){
        sum = sineTaylor(radians, num);
        if (abs(sum - sin(radians))<epsilon) break;
        ++num;
    }
    return num;
}

double nFacRobust(unsigned int n){
    if (n > NFAK_LIMIT) throw "bitch";
    else return nFac(n);
}

void testnFacRobust(){
    int testCase[3] = { 0, 8, NFAK_LIMIT + 1};
    double fac{0};
    for (int i = 0; i < 3; ++i){
        try{
            fac = nFacRobust(testCase[i]);
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
            continue;
        }
        std::cout << fac << std::endl;
    } 
}
