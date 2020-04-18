#include <iostream>

float clip(float n, float lower, float upper);

struct Color{
    int r; 
    int g; 
    int b;
    Color():r{0}, g{0}, b{0}{};
    Color(int red, int green, int blue):r{clip(red, 0, 255)}, 
    g{clip(green, 0, 255)}, b{clip(blue, 0, 255)}{};

};

typedef float Kernel[3][3];

class Image{
    Color* data;
    unsigned int width;
    unsigned int height;
public: 
    Image(int width, int height);
    Image(const Image& other);
    ~Image();
    Image& operator<(Image rhs);
    Color getPixel(int x, int y);
    void setPixel(int x, int y, Color c);
    Image grayscale();
    Image threshold(unsigned int t);
    Image operator+(Image other);
    Color applyKernel(int x, int y, Kernel k);
    Image convolve(Kernel k);
};

