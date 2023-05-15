#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsNum;

        public:
        Cowboy(string, Point); // - 6 bullets & 110 LP ALLWAYS
        ~Cowboy() override = default;
        Cowboy(const Cowboy&) = delete;               // copy constructor
        Cowboy& operator=(const Cowboy&) = delete;    // copy assignment operator
        Cowboy(Cowboy&&) = delete;                    // move constructor
        Cowboy& operator=(Cowboy&&) = delete;         // move assignment operator
        void shoot(Character*);
        bool hasboolets();
        void reload();
        string print() override;
        int GetBulletsNum();
    };
}