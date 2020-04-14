#include "Task3.h"

float normalize(float v, float vmin, float vmax){
    if (v < vmin) return 0.0;
    if (v > vmax) return 1.0;
    return (v-vmin)/(vmax-vmin);
}

Array2D gradient(int xdim, int ydim){
    Array2D array{xdim, ydim};
    float first{0.0};
    float delta = static_cast<float>(10.0/(xdim*ydim));
    for (int y = 0; y < array.getYdim; ++y){
        for (int x = 0; x < array.getXdim; ++x){
            array[y][x] = first;
            first += delta;
        }
    }
    return array;
}

Array2D heatInit(int size){
    Array2D array{size, size};
    for (int x = 0; x < array.getXdim; ++x){
        array[size-1][x] = 100.0;
    }
    return array;
}   

Array2D heatNext(Array2D& H){
    Array2D next{H};
    for (int y = 1; y < H.getYdim()-1; ++y){
        for (int x = 1; x < H.getXdim()-1; ++x){
            next[y][x] = (H[y][x-1]+H[y-1][x]+H[y][x+1]+H[y+1][x])/4;
        }
    }
    return next;
}
