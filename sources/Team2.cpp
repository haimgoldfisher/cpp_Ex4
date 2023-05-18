#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character* warrior) : Team(warrior)
    {

    }

    void Team2::addingStrategy(Character* newWarrior) // the order is by adding order
    {
        this->getWarriors().push_back(newWarrior);
    }
}