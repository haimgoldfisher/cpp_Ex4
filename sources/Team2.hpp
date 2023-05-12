#pragma once

#include "Team.hpp"

namespace ariel
{
    class Team2 : Team
    {
        
        public:
        Team2(Character*); // it creates a team, using a group member
        ~Team2() override = default;
        Team2(const Team2&) = delete;               // copy constructor
        Team2& operator=(const Team2&) = delete;    // copy assignment operator
        Team2(Team2&&) = delete;                    // move constructor
        Team2& operator=(Team2&&) = delete;         // move assignment operator
    };
}