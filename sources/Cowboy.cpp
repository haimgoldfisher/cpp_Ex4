#include "Cowboy.hpp"


namespace ariel
{
    Cowboy::Cowboy(string _name, Point _point) : Character(_name, _point, 110), bulletsNum(6){}
    void Cowboy::shoot(Character* other)
    {
        if(other == this) // cannot shoot himself 
        {
            throw runtime_error("A cowboy cannot shoot at himself!");
        }
        if (!this->isAlive())
        {
            throw runtime_error("A dead cowboy cannot shoot!");
        }
        if (!other->isAlive())
        {
            throw runtime_error("A cowboy cannot shoot at dead character!");
        }
        if (this->hasboolets())
        {
            other->hit(10);
            this->bulletsNum--;
        }
    }
    bool Cowboy::hasboolets() const
    {
        return this->bulletsNum > 0;
    }
    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw runtime_error("A dead cowboy cannot reload!");
        }
        this->bulletsNum = 6;
    }
    string Cowboy::print() const
    {
        return "C: " + Character::print();
    }

    int Cowboy::getBulletsNum() const
    {
        return this->bulletsNum;
    }

    void Cowboy::fight(Character* other)
    {
        if (this->hasboolets())
        {
            this->shoot(other);
        }
        else
        {
            this->reload();
        }
    }
    Role Cowboy::getRole() const
    {
        return COWBOY;
    }
}