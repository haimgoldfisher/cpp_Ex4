#include "Team.hpp"

namespace ariel
{
    Team::Team(Character* warrior) : leader(warrior), warriorsNum(1)
    {
        if (warrior->hasTeam())
        {
            throw runtime_error(warrior->getName() + " already in a team!");
        }
        if (warrior->isAlive())
        {
            liveWarriors = 1;
        }
        warrior->setTeam(); // flag = true
        this->warriors.push_back(warrior);
    }

    Team::~Team()
    {
        for (Character* warrior : this->warriors)
        {
            delete warrior;
        }
    }

    void Team::addingStrategy(Character* newWarrior) 
    {
        if (newWarrior->getRole() == NINJA) 
        {
            this->warriors.push_back(newWarrior); // trivial case: add the new ninja at last
        } 
        else  // == COWBOY
        {
            int i = 0; // for the index of vector
            for (Character* character : this->warriors) 
            {
                if (character->getRole() == NINJA) // so this new cowboy has to be before first ninja
                {
                    this->warriors.insert(this->warriors.begin() + i, newWarrior); // add the new cowboy before first ninja
                    return; 
                }
                i++;
            }
            this->warriors.push_back(newWarrior); // vector with only cowboys, add at last
        }
    }

    Team& Team::add(Character* newWarrior)
    {
        if (newWarrior->hasTeam())
        {
            throw runtime_error(newWarrior->getName() + " already in a team!");
        }
        if (this->warriorsNum == WARRIORS_LIMIT)
        {
            throw runtime_error("Team is full! cannot add a warrior!");
        }
        newWarrior->setTeam(); // flag = true
        this->warriorsNum++; // num of warriors
        if (newWarrior->isAlive()) // insert a dead character to a team
        {
            liveWarriors++; // num of live warriors 
        }
        this->addingStrategy(newWarrior);
        return *this;
    }

    int Team::stillAlive()
    {
        return this->liveWarriors;
    }

    vector<Character*>& Team::getWarriors()
    {
        return this->warriors;
    }

    void Team::killMember()
    {
        this->liveWarriors--;
    }

    Character* Team::closestToLeader(Team* team)
    {
        double minDist = MAX_DOUBLE;
        Character* chosen = nullptr;
        for (Character* warrior : team->warriors)
        {
            if (warrior->isAlive()) // cannot be the leader since he's dead
            {
                double tempDist = this->leader->distance(warrior);
                if (tempDist < minDist)
                {
                    chosen = warrior;
                    minDist = tempDist;
                }
            }
        }
        return chosen;
    }

    void Team::attack(Team* other)
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
        if (!this->leader->isAlive()) // when leader is dead, the team chooses a new leader
        {
            this->leader = this->closestToLeader(this); // the closest warrior from this team to this dead leader
        }
        Character* victim = this->closestToLeader(other); // the closest warrior from other team to this leader
        for (Character* warrior : warriors) 
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
    void Team::print()
    {
        for (Character* warrior : warriors)
        {
            cout << warrior->print() << endl;
        }
    }
    Character* Team::getLeader()
    {
        return this->leader;
    }

    void Team::setLeader(Character* warrior)
    {
        this->leader = warrior;
    }
}