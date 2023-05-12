#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YountNinja.hpp"
using namespace ariel;


namespace ariel
{
    class Team
    {
        
        public:
        Team(Character*); // it creates a team, using a group member
        Team& add(Character*); // maybe should be void
        int stillAlive();
        void attack(Team*);
        virtual void print();
    };
}