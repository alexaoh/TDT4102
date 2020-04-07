#include <iostream>
#include <cmath>
#include <math.h> //Nare for å aksessere M_PI.
#include <vector>

const double PI = M_PI;
const int NFAK_LIMIT{12000000}; //Vilkårlig stor antall ledd;
double radian(double degree);
double nFac(unsigned int n);
double sineTaylorTerm(double x, int n);
double sineTaylor(double x, int n);
int testTaylor(double degree, double epsilon);
double nFacRobust(unsigned int n);
void testnFacRobust();
