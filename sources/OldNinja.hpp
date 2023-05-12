#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        // LP = 150, speed = 8
        public:
        OldNinja(string, Point);
        ~OldNinja(){}
    };
}