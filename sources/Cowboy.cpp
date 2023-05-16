#include "Cowboy.hpp"


namespace ariel
{
    Cowboy::Cowboy(string _name, Point _point) : Character(_name, _point, 110), bulletsNum(6){}
    void Cowboy::shoot(Character* other)
    {
        if(other != this) // cannot shoot himself 
        {
            other->hit(10);
        }
    }
    bool Cowboy::hasboolets()
    {
        return this->bulletsNum > 0;
    }
    void Cowboy::reload()
    {
        this->bulletsNum = 6;
    }
    string Cowboy::print()
    {
        return "C: " + Character::print();
    }

    int Cowboy::getBulletsNum()
    {
        return this->bulletsNum;
    }
}