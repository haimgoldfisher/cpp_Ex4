#include "Cowboy.hpp"


namespace ariel
{
    Cowboy::Cowboy(string _name, Point& _point) : Character(_name, _point, 110), bulletsNum(6){}
    void Cowboy::shoot(Character* character)
    {

    }
    bool Cowboy::hasboolets()
    {
        return false;
    }
    void Cowboy::reload()
    {

    }
    string Cowboy::print()
    {
        return "C " + Character::print();
    }
}