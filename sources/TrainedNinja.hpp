#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

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