#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Character.hpp"

namespace ariel
{
        Character::Character(string _name, Point& _point, int _lp) : name(_name), location(_point), lifePoints(_lp){}
        bool Character::isAlive()
        {
            return true;
        }
        double Character::distance(Character* character)
        {
            return 0;
        }
        void Character::hit(int damage)
        {
            return;
        }
        string Character::getName()
        {
            return this->name;
        }
        Point Character::getLocation()
        {
            return Point(0,0);
        }
        string Character::print()
        {
            return "";
        }
}