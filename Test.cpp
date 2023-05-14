#pragma

#include "doctest.h"
#include <stdexcept>
#include <iostream>
using namespace std;
#include "sources/Team.hpp"
using namespace ariel;

template<typename Base, typename T> // to check inheritance
inline bool instanceof(const T *ptr) 
{
   return dynamic_cast<const Base*>(ptr) != nullptr; // the cast from child to parent must be possible
}

TEST_CASE("Point TEST:")
{
    CHECK_NOTHROW(Point(0,0));
    // ILLEGAL POINTS???
    Point a(0,0), b(1,0);
    CHECK_EQ(a.distance(b), 1);
    // more dists
    CHECK_EQ(Point(1,1).distance(Point(4,5)), 5);
    CHECK_EQ(Point(-4,6).distance(Point(2,-2)), 10);
    Point move = a.moveTowards(b, 0.5);
    CHECK((move.getX() == 0.5) + (move.getY() == 0.5) == 2);
    Point move2 = a.moveTowards(b, 0);
    CHECK((move2.getX() == 0) + (move2.getY() == 0) == 2);
    CHECK_THROWS(a.moveTowards(b, -1)); // distance cannot be negative
    Point start(2, 4), target(-1, 7);
    Point middle = start.moveTowards(target, 3);
    CHECK(start.distance(middle) + middle.distance(target) == start.distance(target)); // A->B + B->C = A->C
    CHECK_NOTHROW(b.print());
}

TEST_CASE("Cowboy TEST:")
{
    // Cowboy starts with 110 LP & 6 Bullets
    Point p1(0,0);
    Cowboy *good = new Cowboy("good", p1);
    Cowboy *bad = new Cowboy("bad", p1);
    Cowboy *ugly = new Cowboy("ugly", p1);

    CHECK(instanceof<Character, Cowboy>(good)); // since Cowboy inherits from Character
    CHECK_EQ(good->getName(), "good");
    CHECK(bad->hasboolets());
    CHECK_EQ(bad->GetBulletsNum(), 6);
    CHECK(ugly->isAlive());
    CHECK_NOTHROW(good->print());
    CHECK((bad->getLocation().getX() == p1.getX()) + (bad->getLocation().getY() == p1.getY()) == 2);
    CHECK_EQ(ugly->getLP(), 110);
    good->hit(50);
    CHECK_EQ(good->getLP(), 60); // 110 - 50 = 60
    good->shoot(bad);
    CHECK_EQ(bad->getLP(), 100); // 110 - 10 = 100
    int iterCounter = 0;
    while (ugly->isAlive() > 0) // good shoots ugly until ugly dies
    {
        if (good->hasboolets())
        {
            good->shoot(ugly); // 5 ->* 4 ->* 3 ->* 2 ->* 1 ->* 0 -> 6 ->* 5 ->* 4 ->* 3 ->* 2 ->* 1 ->* 0 => 11 shoots
        }
        else good->reload();
        if (iterCounter > 20)
        {
            CHECK(1 == 2); // just throwing something because it doesnt work
            break;
        }
        iterCounter++;
    }
    CHECK_EQ(ugly->getLP(), 0);
    CHECK_EQ(good->GetBulletsNum(), 0); // according to the comment ^
}

TEST_CASE("Old Ninja TEST:")
{
    // Old Ninja starts with 150 LP & 8 Speed
    Point p1(0,0);
    OldNinja *splinter = new OldNinja("Splinter", p1); 
    OldNinja *shredder = new OldNinja("Shredder", p1);
}

TEST_CASE("Trained Ninja TEST:")
{
    // Trained Ninja starts with 120 LP & 12 Speed
    Point p1(0,0);
    TrainedNinja *leonardo = new TrainedNinja("Leonardo", p1); 
    TrainedNinja *raphael = new TrainedNinja("Raphael", p1);
}

TEST_CASE("Yount Ninja TEST:")
{
    // Yount Ninja starts with 100 LP & 14 Speed
    Point p1(0,0);
    YountNinja *donatello = new YountNinja("Donatello", p1); 
    YountNinja *michelangelo = new YountNinja("Michelangelo", p1);
}