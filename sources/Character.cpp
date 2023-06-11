
#include "Character.hpp"

namespace ariel
{
        Character::Character(string _name, Point _point, int _lp) : name(_name), location(_point), lifePoints(_lp), inTeam(false){}

        bool Character::isAlive() const
        {
            return this->lifePoints > 0;
        }

        double Character::distance(Character* other) const
        {
            return this->location.distance(other->location); // using Point::distance(Point)
        }

        void Character::hit(int damage)
        {
            if(damage < 0)
            {
                throw invalid_argument("damage cannot be negative!");
            }
            if (damage >= this->lifePoints)
            {
                this->lifePoints = 0; // to avoid negative lp
                return;
            }
            this->lifePoints -= damage;
        }

        int Character::getLP() const
        {
            return this->lifePoints;
        }

        string Character::getName() const
        {
            return this->name;
        }

        Point Character::getLocation() const
        {
            return this->location;
        }

        void Character::setLocation(Point& other)
        {
            this->location = other;
        }

        void Character::setTeam()
        {
            if (this->inTeam)
            {
                throw runtime_error(this->name + " already in a team!");
            }
            this-> inTeam = true;
        }

        string Character::print() const
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

        bool Character::hasTeam() const
        {
            return this->inTeam;
        }
}