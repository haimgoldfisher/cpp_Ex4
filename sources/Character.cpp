
#include "Character.hpp"

namespace ariel
{
        Character::Character(string _name, Point _point, int _lp) : name(_name), location(_point), lifePoints(_lp){}

        bool Character::isAlive()
        {
            return this->lifePoints > 0;
        }

        double Character::distance(Character* other)
        {
            return this->location.distance(other->location); // using Point::distance(Point)
        }

        void Character::hit(int damage)
        {
            if (damage >= this->lifePoints)
            {
                this->lifePoints = 0; // to avoid negative lp
                return;
            }
            this->lifePoints -= damage;
        }

        int Character::getLP()
        {
            return this->lifePoints;
        }

        string Character::getName()
        {
            return this->name;
        }

        Point Character::getLocation()
        {
            return this->location;
        }

        void Character::setLocation(Point& other)
        {
            this->location = other;
        }

        string Character::print()
        {
            string details = "Name: ";
            if (this->isAlive() > 0) // add LP only if alive
            {
                details += this->name + ", Life Points: " + to_string(this->lifePoints) + ", ";
            }
            else // name in () and no LP
            {
                details += "(" + this->name + "), ";
            }
            details += "Location: (" + to_string(this->location.getX()) + "," + to_string(this->location.getY()) += ")";
            return details;
        }
}