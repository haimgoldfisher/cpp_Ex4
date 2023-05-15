#include "Team.hpp"

namespace ariel
{
    Team::Team(Character* warrior) : leader(warrior), warriorsNum(1)
    {}
    Team& Team::add(Character* newWarrior)
    {
        return *this;
    }
    int Team::stillAlive()
    {
        return 0;
    }
    void Team::attack(Team* other)
    {

    }
    void Team::print()
    {
        
    }
    Character* Team::getLeader()
    {
        return this->leader;
    }
}