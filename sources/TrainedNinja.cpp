#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "TrainedNinja.hpp"


namespace ariel
{
    TrainedNinja::TrainedNinja(string _name, Point _point) : Ninja(_name, _point, 120, 12){}
}