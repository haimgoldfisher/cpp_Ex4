#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        // LP = 150, speed = 8
        public:
        OldNinja(string, Point); // ctor: name + location
        ~OldNinja() override = default; // dtor
        OldNinja(const OldNinja&) = delete; // copy ctor
        OldNinja& operator=(const OldNinja&) = delete; // copy assignment operator
        OldNinja(OldNinja&&) = delete; // move ctor
        OldNinja& operator=(OldNinja&&) = delete; // move assignment operator
    };
}