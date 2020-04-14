#include <iostream>
#include "Task2.h"

float normalize(float v, float vmin, float vmax);
Array2D gradient(int xdim, int ydim);
Array2D heatInit(int size);
Array2D heatNext(Array2D& H);
