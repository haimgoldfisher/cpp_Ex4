#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsNum;

        public:
        Cowboy(string, Point&); // - 6 bullets & 110 LP ALLWAYS
        ~Cowboy(){}
        void shoot(Character*);
        bool hasboolets();
        void reload();
        string print() override;
    };
}