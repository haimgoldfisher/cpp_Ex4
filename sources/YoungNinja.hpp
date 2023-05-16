#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        // LP = 100, speed = 14
        public:
        YoungNinja(string, Point); // ctor: name + location
        ~YoungNinja() override = default; // dtor
        YoungNinja(const YoungNinja&) = delete; // copy ctor
        YoungNinja& operator=(const YoungNinja&) = delete; // copy assignment operator
        YoungNinja(YoungNinja&&) = delete; // move ctor
        YoungNinja& operator=(YoungNinja&&) = delete; // move assignment operator
    };
}