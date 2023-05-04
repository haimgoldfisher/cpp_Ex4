#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Point.hpp"


namespace ariel
{
    Point::Point(double _x, double _y) : x(_x), y(_y) 
    {
        
    }
    double Point::distance(const Point) const
    {
        return 0; // IMPLEMENT LATER
    }
    void Point::print()
    {
        cout << "(" << this->x << "," << this->y << ")";
    }
    Point Point::moveTowards (const Point target, double distance) const
    {
        return Point(0,0); // IMPLEMENT LATER
    }
}