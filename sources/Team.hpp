#pragma once

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

constexpr int WARRIORS_LIMIT = 10;

namespace ariel
{
    class Team
    {
        int warriorsNum = 0;
        Character* leader;
        vector<Character*> warriors;

        public:
        Team(Character*); // it creates a team, using a group member
        virtual ~Team() = default; // dtor
        Team(const Team&) = delete; // copy ctor
        Team& operator=(const Team&) = delete; // copy assignment operator
        Team(Team&&) = delete; // move ctor
        Team& operator=(Team&&) = delete; // move assignment operator
        Team& add(Character*); // maybe should be void
        int stillAlive(); // returns the amount of live warriors
        void attack(Team*); // all the team attack the other team
        void print(); // prints all the members of the team
        Character* getLeader(); // returns a pointer of the leader
    };
}