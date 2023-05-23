#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character* warrior) : Team(warrior)
    {}

    void SmartTeam::addingStrategy(Character* newWarrior) // ninjas before cowboys
    {
        if (newWarrior->getRole() == COWBOY) 
        {
            this->getWarriors().push_back(newWarrior); // trivial case: add the new cowboy at last
        } 
        else  // == NINJA
        {
            int i = 0; // for the index of vector
            for (Character* character : this->getWarriors()) 
            {
                if (character->getRole() == COWBOY) // so this new ninja has to be before first cowboy
                {
                    this->getWarriors().insert(this->getWarriors().begin() + i, newWarrior); // add the new ninja before first cowboy
                    return; 
                }
                i++;
            }
            this->getWarriors().push_back(newWarrior); // vector with only ninjas, add at last
        }
    }

    Character* SmartTeam::findWeakest(Team* other)
    {
        int minLP = MAX_INT;
        Character* chosen = nullptr;
        for (Character* warrior : other->getWarriors())
        {
            if (warrior->isAlive()) 
            {
                int tempLP = warrior->getLP();
                if (tempLP < minLP)
                {
                    chosen = warrior;
                    minLP = tempLP;
                }
            }
        }
        return chosen;
    }

    Character* SmartTeam::bestCloseToMe(Team* other, Character* me)
    {
        Character* ninja = nullptr;
        Character* cowboy = nullptr;
        double ninjaDist = MAX_DOUBLE;
        double cowboyDist = MAX_DOUBLE;
        double tempDistNinja, tempDistCowboy;
        for (Character* warrior : other->getWarriors())
        {
            if (warrior->isAlive()) // cannot be the leader since he's dead
            {
                if (warrior->getRole() == COWBOY)
                {
                    tempDistCowboy = me->distance(warrior);
                    if (tempDistCowboy < cowboyDist)
                    {
                        cowboyDist = tempDistCowboy;
                        cowboy = warrior;
                    }
                }
                else // (warrior->getRole() == NINJA)
                {
                    tempDistNinja = me->distance(warrior);
                    if (tempDistNinja < ninjaDist)
                    {
                        ninjaDist = tempDistNinja;
                        ninja = warrior;
                    }
                }
            }
        }
        // trivial - only cowboy / ninja
        if (ninja == nullptr)
        {
            return cowboy;
        }
        else if (cowboy == nullptr)
        {
            return ninja;
        }
        else
        {
            // now we have dist to ninja, dist to cowboy (and damage of them both). lets add the LP factor
            // int cowboyLP = cowboy->getLP();
            int ninjaLP = ninja->getLP();
            int myLP = me->getLP(); 
            if (myLP > ninjaLP || ninjaLP <= 40) // stronger than ninja or can kill him in one slash
            {
                return ninja;
            }
            return cowboy;
        }
    }

    void SmartTeam::attackingStrategy(Team* other)
    {
        Character* victim;
        for (Character* warrior : this->getWarriors()) 
        {
            if (warrior->isAlive()) // dead warrior cannot attack
            {
                if (warrior->getRole() == NINJA)
                {
                    victim = this->bestCloseToMe(other, warrior); // the closest warrior from other team to this ninja
                }
                else // (warrior->getRole() == COWBOY)
                {
                    victim = this->findWeakest(other); // the warrior with lowest LP
                }
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