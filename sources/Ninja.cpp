#include "Ninja.hpp"


namespace ariel
{
    Ninja::Ninja(string _name, Point _point, int lp, int _speed) : Character(_name, _point, lp), speed(_speed){}
    void Ninja::move(Character* other)
    {
        if (!this->isAlive())
        {
            throw runtime_error("A dead ninja cannot move!");
        }
        Point toMove(Point::moveTowards(this->getLocation(), other->getLocation(), this->speed));
        this->setLocation(toMove);
    }
    void Ninja::slash(Character* other)
    {
        if(other == this) // cannot slash himself
        {
            throw runtime_error("A ninja cannot slash himself!");
        }
        if (!this->isAlive())
        {
            throw runtime_error("A dead ninja cannot slash!");
        }
        if (!other->isAlive())
        {
            throw runtime_error("A ninja cannot slash dead character!");
        }
        if (this->distance(other) <= 1) // close enough to target
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
    void Ninja::fight(Character* other)
    {
        if (this->distance(other) > 1)
        {
            this->move(other);
        }
        else
        {
            this->slash(other);
        }
    }
    Role Ninja::getRole()
    {
        return NINJA;
    }
}