#pragma once

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YountNinja.hpp"

constexpr int WARRIORS_LIMIT = 10;

namespace ariel
{
    class Team
    {
        int warriorsNum = 0;
        Character* leader;

        public:
        Team(Character*); // it creates a team, using a group member
        virtual ~Team() = default;
        Team& add(Character*); // maybe should be void
        int stillAlive();
        void attack(Team*);
        virtual void print();
    };
}