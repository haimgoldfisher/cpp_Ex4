#pragma once
#include <iostream>
using namespace std;


namespace ariel
{
    class Point
    {
        double x;
        double y;

        public:
        Point(double, double); // ctor: x & y 
        double distance(Point); // it returns the distance between two Points
        void print(); // it prints a Point in '(x,y)' form
        Point moveTowards (Point, double); // it returns the closest point from the source point to the target, considering the given distance
        int getX();
        int getY();
    };
}