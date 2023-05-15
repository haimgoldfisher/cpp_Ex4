#include "Ninja.hpp"


namespace ariel
{
    Ninja::Ninja(string _name, Point _point, int lp, int _speed) : Character(_name, _point, lp), speed(_speed){}
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
    int Ninja::getSpeed()
    {
        return this->speed;
    }
}