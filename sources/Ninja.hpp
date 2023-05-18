#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
        int speed = 0; // num of distance units the ninja can move, 0 since ninja is an abstract object

        public:
        Ninja(string, Point, int, int); // ctor: name, location, lp and speed
        ~Ninja() override = default; // dtor
        Ninja(const Ninja&) = delete; // copy ctor
        Ninja& operator=(const Ninja&) = delete; // copy assignment operator
        Ninja(Ninja&&) = delete; // move ctor
        Ninja& operator=(Ninja&&) = delete; // move assignment operator
        void move(Character*); // move to character, considering speed
        void slash(Character*); // hit character, if able to, 40 lp
        string print() override;
        int getSpeed(); // speed getter
        void fight(Character* opponent) override;
        Role getRole() override; // ninja
    };
}