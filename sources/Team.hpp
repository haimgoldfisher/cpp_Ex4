#pragma once

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include <limits>

constexpr int WARRIORS_LIMIT = 10;
constexpr double MAX_DOUBLE = numeric_limits<double>::max();
constexpr double MAX_INT = numeric_limits<int>::max();

namespace ariel
{
    class Team
    {
        int warriorsNum; // num of warrior in Team (?/10)
        int liveWarriors; // num of alive warriors in Team
        Character* leader; // pointer to leader of Team
        vector<Character*> warriors; // vector of Characters

        public:
        Team(Character*); // it creates a team, using a group member
        virtual ~Team(); // dtor
        Team(const Team&) = delete; // copy ctor
        Team& operator=(const Team&) = delete; // copy assignment operator
        Team(Team&&) = delete; // move ctor
        Team& operator=(Team&&) = delete; // move assignment operator
        Team& add(Character*); // the classic body of adding
        virtual void addingStrategy(Character*); // the specific adding strategy of adding a new warrior to vector
        virtual void attackingStrategy(Team*); // the specific attacking strategy of attacking other team
        int stillAlive() const; // returns the amount of live warriors
        vector<Character*>& getWarriors(); // vector getter
        void attack(Team*); // all the team attack the other team
        void print() const; // prints all the members of the team
        Character* getLeader() const; // returns a pointer of the leader
        void setLeader(Character*); // update the leader
        void killMember(); // liveWarriors 'setter' (reduce by one)
        virtual Character* closestToLeader(const Team*) const; // finds the closest warrior from the chosen team to this team's leader 
    };
}