#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>

typedef std::string Plot; //Plot is a class from a graphics library. Did this to stop complaining compiler.  

const int N = 100;
float x[N];
float y[N];

void plotPoints(Plot& plt, float x[], float v[], int n);
void plotPointLines(Plot& plt, float x[], float v[], int n);
void alim(float a[], int n, float& amin, float& amax);
float scaleX(Plot& plt, float x, float xmin, float xmax);
float scaleY(Plot& plt, float y, float ymin, float ymax);
void plotScaled(Plot& plt, float x[], float y[], int n, std::string color, float xmin, float xmax, float ymin, float ymax);
void plotScaled(Plot& plt, float x[], float y[], int n, std::string color = "black");

float sin(float arg);
float cos(float arg);
constexpr float M_PI = 3.14159265;

void plotMathsFuncs(Plot& plt);
void plotSeries(Plot& plt, float** x, float** y, int n, int m);

struct Series{
    float** x; 
    float** y; 
    int m; 
    int n; 
};

Series loadSeries(std::string filename);
