#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "YountNinja.hpp"


namespace ariel
{
    YountNinja::YountNinja(string _name, Point _point) : Ninja(_name, _point, 100, 14){}
}