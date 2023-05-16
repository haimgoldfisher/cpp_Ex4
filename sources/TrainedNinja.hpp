#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        // LP = 120, speed = 12
        public:
        TrainedNinja(string, Point); // ctor: name + location
        ~TrainedNinja() override = default; // dtor
        TrainedNinja(const TrainedNinja&) = delete; // copy ctor
        TrainedNinja& operator=(const TrainedNinja&) = delete; // copy assignment operator
        TrainedNinja(TrainedNinja&&) = delete; // move ctor
        TrainedNinja& operator=(TrainedNinja&&) = delete; // move assignment operator
    };
}