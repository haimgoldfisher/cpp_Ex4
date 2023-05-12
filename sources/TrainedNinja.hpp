#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        // LP = 120, speed = 12
        public:
        TrainedNinja(string, Point);
        ~TrainedNinja() override = default;
        TrainedNinja(const TrainedNinja&) = delete;               // copy constructor
        TrainedNinja& operator=(const TrainedNinja&) = delete;    // copy assignment operator
        TrainedNinja(TrainedNinja&&) = delete;                    // move constructor
        TrainedNinja& operator=(TrainedNinja&&) = delete;         // move assignment operator
    };
}