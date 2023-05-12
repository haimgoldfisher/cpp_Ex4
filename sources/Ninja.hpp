#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
        int speed = 0;

        public:
        Ninja(string, Point&, int, int); // name, location, lp and speed
        ~Ninja(){}
        void move(Character*);
        void slash(Character*);
        string print() override;
    };
}