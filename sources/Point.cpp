#include "Point.hpp"


namespace ariel
{
    Point::Point(double _x, double _y) : x(_x), y(_y) 
    {
        
    }
    double Point::distance(Point other)
    {
        return sqrt(pow(other.getX()-this->getX(), 2) + pow(other.getY()-this->getY(), 2));
    }
    void Point::print()
    {
        cout << "(" << this->x << "," << this->y << ")";
    }
    Point Point::moveTowards(Point source, Point target, double possibleDist)
    {
        Point a(0,0);
        return a;
    }
    double Point::getX()
    {
        return this->x;
    }
    double Point::getY()
    {
        return this->y;
    }
}