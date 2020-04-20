#include "Task3.h"

void Turtle::setPosition(float x, float y){
    this->x = x; 
    this->y = y;
}

std::vector<float> Turtle::getPosition(){
    std::vector<float> returns; 
    returns.push_back(x);
    returns.push_back(y);
    return returns; //Blir litt annerledes i grafikkbiblio de bruker!
}

Turtle::Turtle(int width, int height, Fl_Color bgColor = FL_WHITE, Fl_Color color = FL_BLACK):
x{0.0}, y{0.0}, angle{0.0}, lineWidth{1.0}, width{width}, height{height}, bgColor{bgColor}, color{color}{
    if (!canvas.create(width, height)) throw;
    clear();
}

void Turtle::forward(float distance){
    float rad = deg2rad(angle);
    float x1 = x + distance*cos(rad);
    float y1 = y + distance*sin(rad);
    drawLine(x,y,x1, y1);
}

void Turtle::backward(float distance){
    forward(-distance);
}

void Turtle::left(float angle){
    this->angle += angle;
}   

void Turtle::right(float angle){
    this->angle -= angle;
}

void hexagon(Turtle* turtle){
    fl_color(200, 100, 0);
    for (int i = 0, i<6; ++i){
        turtle->forward(100);
        turtle->left(120);
    }
}

float randRange(float min, float max){
    srand(static_cast<unsigned int>(time(nullptr)));
    return min + (max-min)*(static_cast<float>(rand()/RAND_MAX));
}

void randomWalk(Turtle* turtle, int steps){
    for (int i = 0; i<steps; ++i){
        turtle->left(randRange(-90, 90));
        turtle->forward(randRange(0,10));
    }
}

void koch(Turtle* turtle, float length, int level){
    if (level = 0){
        turtle->forward(length);
    }else{
        length = length / 3;
        level -= 1;
        koch(turtle, length, level);
        turtle->left(60);
        koch(turtle, length, level);
        turtle->right(120);
        koch(turtle, length, level);
        turtle->left(60);
        koch(turtle, length, level);
    }
}

void snowflake(Turtle* turtle, float length, int level){
    koch(turtle, length, level);
    turtle->right(120);
    koch(turtle, length, level);
    turtle->right(120);
    koch(turtle, length, level);
    turtle->right(120);
}
