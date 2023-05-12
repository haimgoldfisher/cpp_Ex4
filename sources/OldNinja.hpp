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
        OldNinja(const OldNinja&) = delete;               // copy constructor
        OldNinja& operator=(const OldNinja&) = delete;    // copy assignment operator
        OldNinja(OldNinja&&) = delete;                    // move constructor
        OldNinja& operator=(OldNinja&&) = delete;         // move assignment operator
    };
}