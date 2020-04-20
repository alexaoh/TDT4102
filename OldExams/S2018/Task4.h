#include "Task3.h"

class Wally : public Turtle {
    float speed;
    float turn;
public: 
    float getSpeed() const { return speed; }
    float getTurn() const { return turn; }
    void setSpeed(float speed){ this->speed = speed; }
    void setTurn(float turn){ this->turn = turn; }
    Wally(float speed, float turn, float width, float height):Turtle(width, height), speed{speed}, turn{turn}{}
    void forward(float distance) override;
    float sense(); //Implemented in the task already.
    void run();
};
