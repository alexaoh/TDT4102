#include "Task4.h"

void Wally::forward(float distance){
    //tolket oppgaven slik!
    if (this->x >= width/2 || this->x <= -width/2 || this->y >= height/2 || this->y <= -height/2){
        this->backward(distance);
    }
}

void Wally::run(){
    while (true){
        float distance = sense();
        float randomNum = randRange(-5, 5);
        if (distance < 100){
            left(turn);
        }
        if (distance > 10){
            forward(speed);
        }
        left(randomNum);
    }
}
