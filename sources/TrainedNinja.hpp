#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        // LP = 120, speed = 12
        public:
        TrainedNinja(string, Point);
        ~TrainedNinja(){}
    };
}