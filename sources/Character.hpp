#pragma once

#include "Point.hpp"

typedef enum {COWBOY = 0, NINJA = 1} Role;

namespace ariel
{
    class Character
    {
        string name; // name of the Character
        ariel::Point location; // form of (x,y)
        int lifePoints = 0; // since charcter is an abstract object
        bool inTeam; // return if the Character belongs to a Team

        public:
        Character(string, Point, int); // ctor
        Character(const Character&) = delete; // copy ctor
        Character& operator=(const Character&) = delete; // copy assignment operator
        Character(Character&&) = delete; // move ctor
        Character& operator=(Character&&) = delete; // move assignment operator
        virtual ~Character() = default; // dtor
        
        void hit(int); // LP 'setter' (can only be reduced)
        string getName() const; // name getter
        int getLP() const; // LP getter
        Point getLocation() const; // location getter
        void setLocation(Point&); // location setter;
        virtual Role getRole() const = 0; // since character has no role yet

        bool isAlive() const;
        double distance(Character*) const; // dist between two character
        virtual string print() const; // return details about the character
        bool hasTeam() const; // returns if the character belongs to a team
        void setTeam(); // set that the character has a team
        virtual void fight(Character*) = 0; // every character can fight in his way (shoot/slash)
    };
}