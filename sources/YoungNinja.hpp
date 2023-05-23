#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        // LP = 100, speed = 14
        public:
        YoungNinja(string, Point); // ctor: name + location
    };
}