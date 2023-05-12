#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class YountNinja : public Ninja
    {
        // LP = 100, speed = 14
        public:
        YountNinja(string, Point);
        ~YountNinja() override = default;
        YountNinja(const YountNinja&) = delete;               // copy constructor
        YountNinja& operator=(const YountNinja&) = delete;    // copy assignment operator
        YountNinja(YountNinja&&) = delete;                    // move constructor
        YountNinja& operator=(YountNinja&&) = delete;         // move assignment operator
    };
}