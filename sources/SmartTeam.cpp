#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character* warrior) : Team(warrior)
    {}

    void SmartTeam::attack(Team* other)
    {
        if (other == this)
        {
            throw runtime_error("A team cannot attack itself");
        }
        if (other == nullptr)
        {
            throw invalid_argument("Must attack an exist team");
        }
        if (this->stillAlive() == 0) // the attack team is dead
        {
            return;
        }
        if (other->stillAlive() == 0)
        {
            throw runtime_error("cannot attack dead team!");
        }
        if (!this->getLeader()->isAlive()) // when leader is dead, the team chooses a new leader
        {
            this->setLeader(this->closestToLeader(this)); // the closest warrior from this team to this dead leader
        }
        Character* victim = this->closestToLeader(other); // the closest warrior from other team to this leader
        for (Character* warrior : this->getWarriors()) 
        {
            if (warrior->isAlive()) // dead warrior cannot attack
            {
                // cout << warrior->getName() + " fight " + victim->getName() << endl; 
                warrior->fight(victim); // attack the victim in the warrior's way (shoot/slash)
                if (!victim->isAlive())
                {
                    other->killMember();
                    if (other->stillAlive() == 0)
                    {
                        return;
                    }
                    else
                    {
                        victim = this->closestToLeader(other);
                    }
                }
            }
        }
    }
}