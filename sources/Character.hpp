#pragma once

using namespace std;

#include "Point.hpp"

namespace ariel
{
    class Character
    {
        string name;
        ariel::Point location;
        int lifePoints = 0;

        public:
        Character(string, Point, int);
        virtual ~Character() = default;
        bool isAlive();
        double distance(Character*);
        void hit(int);
        string getName();
        Point getLocation();
        virtual string print();
    };
}