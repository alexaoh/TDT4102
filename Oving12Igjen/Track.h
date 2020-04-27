#pragma once
#include <FL/Fl_Widget.H>
#include <vector>
#include <tuple>
#include "utilities.h"
#include <FL/fl_draw.H>
#include "random"
#include <FL/Fl_JPEG_Image.H>


enum class Obstacle{
    Spill, Boost, Peel, None
};

class Track : public Fl_Widget{ 
    std::vector<std::pair<double, double>> goals;
    std::vector<std::tuple<double, double, Obstacle>> obstacles; 
public: 
    Track();
    void draw() override;
    std::vector<std::pair<double, double>> getGoals() const { return goals; }
    std::vector<std::tuple<double, double, Obstacle>> getObstacles() const { return obstacles; }
};

