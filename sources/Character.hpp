#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Point.hpp"

namespace ariel
{
    class Character
    {
        string name;
        ariel::Point location;
        int lifePoints = 0;

        public:
        Character(string, Point&, int);
        ~Character(){}
        bool isAlive();
        double distance(Character*);
        void hit(int);
        string getName();
        Point getLocation();
        virtual string print();
    };
}