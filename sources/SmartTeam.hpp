#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
        
        public:
        SmartTeam(Character*); // it creates a team, using a group member
        void addingStrategy(Character* newWarrior) override; // the specific adding stategy of adding a new warrior to vector
        void attackingStrategy(Team* other) override; // the specific attacking strategy of attacking other team
        Character* bestCloseToMe(Team*, const Character*) const; // return the ideal closest warrior to ninja
        Character* findWeakest(Team*) const; // find the live character with lowest LP
    };
}