#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel
{
    class Point
    {
        double x;
        double y;

        public:
        Point(double, double); // ctor
        double distance(const Point) const; // it returns the distance between two Points
        void print(); // it prints a Point in '(x,y)' form
        Point moveTowards (const Point, double) const; // it returns the closest point from the source point to the target, considering the given distance
    };
}