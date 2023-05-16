#pragma once
#include <iostream>
#include <cmath>
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
        static Point moveTowards (Point, Point, double); // the closest point from the source point to the target, considering the given distance
        double getX();
        double getY();
    };
}