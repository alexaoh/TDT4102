#include <cmath> 
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

class Vector2d{
public: 
    double x; 
    double y;
    Vector2d(double x, double y):x{x}, y{y}{}
    double length() const;
    Vector2d operator*(double k) const;
};

Vector2d operator+(const Vector2d& vec1, const Vector2d& vec2); //kan ev. returnere en referanse her. 
std::ostream& operator<<(std::ostream& out, const Vector2d& v);
Vector2d vectorSum(const std::vector<Vector2d>& vectors);
void trackStats(const std::vector<Vector2d>& track);
void cleanTrack(std::vector<Vector2d>& track);


class OutsideTrack{
    Vector2d current;
    double trackStart;
    double trackEnd;
    public: 
        OutsideTrack(double firstEdge, double lastEdge):trackStart{firstEdge}, trackEnd{lastEdge}, current{0.0, 0.0}{}
        Vector2d operator()(Vector2d vec){ 
            Vector2d newPos = current + vec;
            if (newPos.x > trackEnd || newPos.y > trackEnd || newPos.x < trackStart || newPos.y < trackStart){
                return {0.0, 0.0};
            } else {
                current = newPos;
                return vec;
            }};
};
