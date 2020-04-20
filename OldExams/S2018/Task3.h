#include <iostream>
#include <vector>
#include "fltk.h"
#include <math.h>
#include <random>

class Turtle{
protected:
    float x,y;
    float angle;
    int width;
    int height;
    float lineWidth;
    Fl_Color color;
    Fl_Color bgColor;
    Fl_Window canvas; //try with this in FLTK. 
    void drawLine(float x0, float y0, float x1, float y1);
public: 
    Turtle(int width, int height, Fl_Color bgColor = FL_WHITE, Fl_Color color = FL_BLACK);
    void clear();
    std::vector<float> getPosition(); //Skulle egt vært en vektor fra SFML her, ikke float. 
    void setPosition(float x, float y);
    float getAngle() { return angle; }
    void setAngle(float angle) { this->angle = angle; }
    int getWidth(){ return width; }
    int getHeight(){ return height; }
    Fl_Color getColor(){ return color; }
    void setColor(Fl_Color color){ this->color = color; }
    void setLineWidth(float lw){ lineWidth = lw; }
    virtual void forward(float distance);
    virtual void backward(float distance);
    virtual void left(float angle);
    virtual void right(float angle);

    float deg2rad(float deg);
};

void hexagon(Turtle* turtle);
float randRange(float min, float max);
void randomWalk(Turtle* turtle, int steps);
void koch(Turtle* turtle, float length, int level);
void snowflake(Turtle* turtle, float length, int level);
