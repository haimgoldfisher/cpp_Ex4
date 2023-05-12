#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "OldNinja.hpp"


namespace ariel
{
    OldNinja::OldNinja(string _name, Point _point) : Ninja(_name, _point, 150, 8){}
}