#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
        int speed = 0;

        public:
        Ninja(string, Point&, int, int); // name, location, lp and speed
        ~Ninja() override = default;
        Ninja(const Ninja&) = delete;               // copy constructor
        Ninja& operator=(const Ninja&) = delete;    // copy assignment operator
        Ninja(Ninja&&) = delete;                    // move constructor
        Ninja& operator=(Ninja&&) = delete;         // move assignment operator
        void move(Character*);
        void slash(Character*);
        string print() override;
    };
}