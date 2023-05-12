#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : Team
    {
        
        public:
        SmartTeam(Character*); // it creates a team, using a group member
        ~SmartTeam() override = default;
        SmartTeam(const SmartTeam&) = delete;               // copy constructor
        SmartTeam& operator=(const SmartTeam&) = delete;    // copy assignment operator
        SmartTeam(SmartTeam&&) = delete;                    // move constructor
        SmartTeam& operator=(SmartTeam&&) = delete;         // move assignment operator
    };
}