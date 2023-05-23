#pragma once

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
        
        public:
        Team2(Character*); // it creates a team, using a group member

        void addingStrategy(Character* newWarrior) override; // the specific adding stategy of adding a new warrior to vector
    };
}