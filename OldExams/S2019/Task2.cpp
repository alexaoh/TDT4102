#include "Task2.h"

double Vector2d::length() const {
    return sqrt(pow(x,2)+pow(y,2));
}

Vector2d operator+(const Vector2d& vec1, const Vector2d& vec2){ 
    Vector2d vec{vec1.x+vec2.x,vec1.y+vec2.y};
    return vec;
}   

Vector2d Vector2d::operator*(double k) const {
    Vector2d vec{x*k, y*k};
    return vec;
}

std::ostream& operator<<(std::ostream& out, const Vector2d& v){
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

Vector2d vectorSum(const std::vector<Vector2d>& vectors){
    Vector2d vecSum{0,0};
    for (const auto x : vectors){
        vecSum = vecSum + x;
    }
    return vecSum;
}

void trackStats(const std::vector<Vector2d>& track){
    double length{0};
    double maxSpeed{0};
    Vector2d endpoint{0,0};
    for (const auto vec : track){
        double len = vec.length();
        length += len;
        double speed = len*1000/static_cast<double>(10);
        if (speed >= maxSpeed) maxSpeed = speed;

    }
    endpoint = vectorSum(track);
    std::cout << "Length: " << std::setprecision(2) << std::fixed << length 
              << " km, max-speed: " << std::setprecision(0) << std::fixed 
              << maxSpeed << " m/min, ended at " << endpoint;
}

void cleanTrack(std::vector<Vector2d>& track){
    std::transform(track.begin(), track.end(), track.begin(), OutsideTrack{0.0, 10.0});

}
