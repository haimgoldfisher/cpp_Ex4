#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Ninja.hpp"


namespace ariel
{
    Ninja::Ninja(string _name, Point& _point, int lp, int _speed) : Character(_name, _point, lp), speed(_speed){}
    void Ninja::move(Character*)
    {

    }
    void Ninja::slash(Character*)
    {

    }
    string Ninja::print()
    {
        return "N " + Character::print();
    }
}