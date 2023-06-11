#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;


namespace ariel
{
    class Point
    {
        private:
        double x;
        double y;

        public:
        Point(double, double); // ctor: x & y 
        double distance(Point) const; // it returns the distance between two Points
        void print() const; // it prints a Point in '(x,y)' form
        static Point moveTowards (Point, Point, double); // the closest point from the source point to the target, considering the given distance
        double getX() const; // returns X value of a given point
        double getY() const; // returns Y value of a given point
    };
}