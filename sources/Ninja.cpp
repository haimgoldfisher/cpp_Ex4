#include "Ninja.hpp"


namespace ariel
{
    Ninja::Ninja(string _name, Point _point, int lp, int _speed) : Character(_name, _point, lp), speed(_speed){}
    void Ninja::move(Character* other)
    {
        // this->setLocation(this->getLocation().moveTowards(other->getLocation(), this->speed));
    }
    void Ninja::slash(Character* other)
    {
        if(other != this && this->distance(other) <= 1) // cannot slash himself + close enough
        {
            other->hit(40);
        }
    }
    string Ninja::print()
    {
        return "N: " + Character::print();
    }
    int Ninja::getSpeed()
    {
        return this->speed;
    }
}