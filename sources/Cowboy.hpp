#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsNum;

        public:
        Cowboy(string, Point&); // - 6 bullets & 110 LP ALLWAYS
        ~Cowboy(){}
        void shoot(Character*);
        bool hasboolets();
        void reload();
        string print() override;
    };
}