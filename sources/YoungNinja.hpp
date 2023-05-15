#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        // LP = 100, speed = 14
        public:
        YoungNinja(string, Point);
        ~YoungNinja() override = default;
        YoungNinja(const YoungNinja&) = delete;               // copy constructor
        YoungNinja& operator=(const YoungNinja&) = delete;    // copy assignment operator
        YoungNinja(YoungNinja&&) = delete;                    // move constructor
        YoungNinja& operator=(YoungNinja&&) = delete;         // move assignment operator
    };
}