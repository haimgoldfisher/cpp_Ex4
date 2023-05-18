#pragma once

#include "Point.hpp"

typedef enum {COWBOY = 0, NINJA = 1} Role;

namespace ariel
{
    class Character
    {
        string name;
        ariel::Point location; // form of (x,y)
        int lifePoints = 0; // since charcter is an abstract object
        bool inTeam;

        public:
        Character(string, Point, int); // ctor
        Character(const Character&) = delete; // copy ctor
        Character& operator=(const Character&) = delete; // copy assignment operator
        Character(Character&&) = delete; // move ctor
        Character& operator=(Character&&) = delete; // move assignment operator
        virtual ~Character() = default; // dtor
        
        void hit(int); // LP 'setter' (can only be reduced)
        string getName(); // name getter
        int getLP(); // LP getter
        Point getLocation(); // location getter
        void setLocation(Point&); // location setter;
        virtual Role getRole() = 0; // since character has no role yet

        bool isAlive();
        double distance(Character*); // dist between two character
        virtual string print(); // return details about the character
        bool hasTeam(); // return if the character belongs to a team
        void setTeam(); // set that the character has a team
        virtual void fight(Character*) = 0; // every character can fight in his way (shoot/slash)
    };
}