#include "Point.hpp"


namespace ariel
{
    Point::Point(double _x, double _y) : x(_x), y(_y) 
    {
        
    }
    double Point::distance(const Point)
    {
        return 0; // IMPLEMENT LATER
    }
    void Point::print()
    {
        cout << "(" << this->x << "," << this->y << ")";
    }
    Point Point::moveTowards (const Point target, double distance)
    {
        return Point(0,0); // IMPLEMENT LATER
    }
    int Point::getX()
    {
        return this->x;
    }
    int Point::getY()
    {
        return this->y;
    }
}