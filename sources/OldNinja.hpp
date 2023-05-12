#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        // LP = 150, speed = 8
        public:
        OldNinja(string, Point);
        ~OldNinja() override = default;
    };
}