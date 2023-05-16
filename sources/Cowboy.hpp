#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsNum; // cowboy has bullets, which he can shoot

        public:
        Cowboy(string, Point); // - 6 bullets & 110 LP ALLWAYS
        ~Cowboy() override = default; // dtor
        Cowboy(const Cowboy&) = delete; // copy ctor
        Cowboy& operator=(const Cowboy&) = delete; // copy assignment operator
        Cowboy(Cowboy&&) = delete; // move ctor
        Cowboy& operator=(Cowboy&&) = delete; // move assignment operator
        void shoot(Character*); // can shoot at other character
        bool hasboolets();
        void reload(); // it reload 6 new bullets
        string print() override;
        int getBulletsNum(); // bullets getter
    };
}