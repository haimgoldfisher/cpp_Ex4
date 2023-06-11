#include "Point.hpp"


namespace ariel
{
    Point::Point(double _x, double _y) : x(_x), y(_y) 
    {
        
    }
    double Point::distance(Point other) const
    {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }
    void Point::print() const
    {
        cout << "(" << this->x << "," << this->y << ")";
    }
    Point Point::moveTowards(Point source, Point target, double possibleDist)
    {
        if (possibleDist < 0) // negative possibleDist case
        {
            throw invalid_argument("Distance cannot be negative!");
        }
        if (possibleDist == 0) // cannot move
        {
            return source;
        }
        double dist = source.distance(target); // using Point::distance
        if (dist <= possibleDist) // target is reachable
        {
            return target;
        }
        // tansform to unit vector (dx, dy):
        double dx = (target.x - source.x) / dist;
        double dy = (target.y - source.y) / dist;
        // now we can stretch the vector according to 'possibleDist' and add it to the source point:
        return Point(source.x + (dx * possibleDist), source.y + (dy * possibleDist));
    }
    double Point::getX() const
    {
        return this->x;
    }
    double Point::getY() const
    {
        return this->y;
    }
}