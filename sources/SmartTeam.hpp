#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
        
        public:
        SmartTeam(Character*); // it creates a team, using a group member
        ~SmartTeam() override = default; // dtor
        SmartTeam(const SmartTeam&) = delete; // copy ctor
        SmartTeam& operator=(const SmartTeam&) = delete; // copy assignment operator
        SmartTeam(SmartTeam&&) = delete; // move ctor
        SmartTeam& operator=(SmartTeam&&) = delete; // move assignment operator

        void attack(Team* opponet) override; // all the team attack the other team
    };
}