#pragma once

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
        Character(const Character&) = delete;               // copy constructor
        Character& operator=(const Character&) = delete;    // copy assignment operator
        Character(Character&&) = delete;                    // move constructor
        Character& operator=(Character&&) = delete;         // move assignment operator
        virtual ~Character() = default;
        bool isAlive();
        double distance(Character*);
        void hit(int);
        string getName();
        Point getLocation();
        virtual string print();
    };
}