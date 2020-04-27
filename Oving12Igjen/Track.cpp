#include "Track.h"

Track::Track():Fl_Widget(10, 10, 10, 10){
    /*
    //Tried to draw a Bernoulli Lemniscate. Does not work as expected.  
    for (int y = screenHeight/4; y<screenHeight*(3/4); ++y){
        double a = 1;
        double x = pow(-1,y)*sqrt(pow(a,2) - pow(y,2) + pow(-1,y)*a*sqrt(pow(a,2)-4*pow(y,2)));
        goals.push_back(std::make_pair(x,y));
    }
    */
    int circles = 70;
    for (int i = 0; i < circles; ++i){
        goals.push_back({screenWidth / 2 + screenWidth / 3.0 * cos(i * 2.0 / circles * 3.14),
			screenHeight / 2 - screenHeight / 3.0 * sin(i * 4.0 / circles * 3.14)});
    }

    //Make obstacles (append to obstacles-vector).
    int nObstacle = 10;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < nObstacle; ++i){
        int randomIndex = rand() % goals.size();
        int randomObst = rand() % 3;
        std::pair<double, double> randomPair = goals[randomIndex];
        obstacles.push_back({randomPair.first, randomPair.second, static_cast<Obstacle>(randomObst)});
    }
    

}

void Track::draw(){
    for (auto pair : goals){
        fl_color(FL_BLACK);
        fl_begin_line();
        fl_circle(pair.first, pair.second, goalRadius);
        fl_end_line();
    }

    for (auto tuple : obstacles){
        if (std::get<2>(tuple) == Obstacle::Spill){
            Fl_JPEG_Image spillImg{"Sprites/spillSprite.jpeg"};
            fl_color(FL_WHITE);
            spillImg.draw(std::get<0>(tuple), std::get<1>(tuple), 50, 50);
        } else if (std::get<2>(tuple) == Obstacle::Boost){
            Fl_JPEG_Image spillImg{"Sprites/boostSprite.jpeg"};
            fl_color(FL_WHITE);
            spillImg.draw(std::get<0>(tuple), std::get<1>(tuple), 20, 20);
        } else if (std::get<2>(tuple) == Obstacle::Peel){
            Fl_JPEG_Image spillImg{"Sprites/peelSprite.jpeg"};
            fl_color(FL_WHITE);
            spillImg.draw(std::get<0>(tuple), std::get<1>(tuple), 30, 30);
        }
    }
}