#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Ninja.hpp"

namespace ariel
{
    class YountNinja : public Ninja
    {
        // LP = 100, speed = 14
        public:
        YountNinja(string, Point);
        ~YountNinja(){}
        
    };
}