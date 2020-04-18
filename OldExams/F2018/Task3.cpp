#include "Task3.h"

float clip(float n, float lower, float upper){
    if (n <= lower) return lower;
    if (n >= upper) return upper;
    if (n > lower && n < upper) return n;
}

Image::Image(int width, int height):width{width}, height{height}{
    data = new Color[width*height];
}

Image::Image(const Image& other):height{other.height}, 
width{other.width}, data{new Color[height*width]}{
    for (unsigned int i = 0; i<height*width; ++i){
        data[i] = other.data[i];
    }
}

Image::~Image(){
    delete[] data;
}

//Tilordningsoperatoren må implementeres for at et Image skal kunne settes likt et annet. 
//For å få til en deep copy, for standard er shallow copy for pointere, som fungerer dårlig i en rekke tilfeller

Color Image::getPixel(int x, int y){
    return data[y*width + x];
}  

void Image::setPixel(int x, int y, Color c){
    data[y*width + x] = c; 
}

Image Image::grayscale(){
    Image copy{*this};
    for (int i = 0; i<width*height; ++i){
        copy.data[i].r = copy.data[i].b = copy.data[i].g = (copy.data[i].g + copy.data[i].r + copy.data[i].b)/3;
    }
    return copy;
}

int thresh(int val, unsigned int t){
    if (val >= t) return 255;
    else return 0;
}

Image Image::threshold(unsigned int t){
    Image newIm{*this};
    for (int i = 0; i<width*height; ++i){
        newIm.data[i].r = thresh(newIm.data[i].r, t);
        newIm.data[i].g = thresh(newIm.data[i].g, t);
        newIm.data[i].b = thresh(newIm.data[i].b, t);
    }
    return newIm;
}

Image Image::operator+(Image other){
    Image copy{*this};
    if (copy.width != other.width || copy.height != other.height) throw;
    for (unsigned int i = 0; i<width*height; ++i){
        Color temp;
        temp.r = (copy.data[i].r + other.data[i].r)/2;
        temp.b = (copy.data[i].b + other.data[i].b)/2;
        temp.g = (copy.data[i].g + other.data[i].g)/2;
        copy.data[i] = temp;
    }
    return copy;
}

Color Image::applyKernel(int x, int y, Kernel k){
    int sumG{0};
    int sumB{0};
    int sumR{0};
    for (int i = 0; i<3; ++i){
        for (int e = 0; e<3; ++e){
            sumG += getPixel(x-1+e, y-1+i).g*k[i][e];  
            sumB += getPixel(x-1+e, y-1+i).b*k[i][e]; 
            sumR += getPixel(x-1+e, y-1+i).r*k[i][e]; 
        }
    }
    return Color{sumR, sumG, sumB};
}

Image Image::convolve(Kernel k){
    Image newImage{*this};
    for (int y = 1; y<height-1; ++y){
        for (int x = 1; x<width-1; ++x){
            newImage.getPixel(x,y) = applyKernel(x, y, k);
        }
    }
    return newImage;
}
