#pragma

#include "doctest.h"
#include <stdexcept>
#include <iostream>
using namespace std;
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
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
    CHECK_THROWS(good->shoot(bad)); // cannot shoot when has no bullets
    good->reload();
    CHECK_EQ(good->GetBulletsNum(), 6);
    CHECK_THROWS(ugly->shoot(good)); // dead cannot shoot
    CHECK_THROWS(good->shoot(ugly)); // cannot shoot at dead warrior
    CHECK_THROWS(good->shoot(good)); // cannot shoot at himself
}

TEST_CASE("Old Ninja TEST:")
{
    // Old Ninja starts with 150 LP & 8 Speed
    Point p1(-8,0), p2(8,0);
    OldNinja *splinter = new OldNinja("Splinter", p1); 
    OldNinja *shredder = new OldNinja("Shredder", p2);
    CHECK_EQ(splinter->getLP(), 150);
    CHECK_EQ(shredder->getSpeed(), 8);
    CHECK(instanceof<Character, Ninja>(splinter)); // since Ninja inherits from Character
    CHECK_EQ(splinter->getName(), "Splinter");
    CHECK((splinter->getLocation().getX() == p1.getX()) + (splinter->getLocation().getY() == p1.getY()) == 2);
    CHECK((shredder->getLocation().getX() == p2.getX()) + (shredder->getLocation().getY() == p2.getY()) == 2);
    CHECK_THROWS(splinter->slash(shredder)); // cannot slash him since they are far from each other
    CHECK_EQ(shredder->getLP(), 150);
    CHECK_EQ(shredder->distance(splinter), 16);
    CHECK_NOTHROW(shredder->move(splinter)); // shredder should go now from (8,0) to (0,0) since its speed is 8
    CHECK((shredder->getLocation().getX() == 0) + (shredder->getLocation().getY() == 0) == 2); // lets be sure its happend
    CHECK_THROWS(shredder->slash(splinter)); // cannot slash him since they are still far from each other
    CHECK_NOTHROW(splinter->move(shredder)); // splinter should go now from (-8,0) to (0,0) since its speed is 8
    CHECK((splinter->getLocation().getX() == 0) + (splinter->getLocation().getY() == 0) == 2); // lets be sure its happend
    // they both should be close enough to slash each other
    CHECK_NOTHROW(splinter->slash(shredder)); // shredder LP: 150 -> 110
    CHECK_EQ(shredder->getLP(), 110);
    int iterCounter = 0;
    while (splinter->isAlive() > 0)
    {
        shredder->slash(splinter); // splinter LP: 150 -> 110 -> 70 -> 30 -> 0
        if (iterCounter > 10)
        {
            CHECK(1 == 2); // just throwing something because it doesnt work
            break;
        }
        iterCounter++;
    }
    CHECK_THROWS(shredder->slash(splinter)); // cannot slash dead
    CHECK_THROWS(splinter->slash(shredder)); // dead cannot slash
    CHECK_THROWS(shredder->slash(shredder)); // cannot slash himself (Harakiri is not allowed here :) )
}

TEST_CASE("Trained Ninja TEST:")
{
    // Trained Ninja starts with 120 LP & 12 Speed
    Point p1(0,0);
    TrainedNinja *leonardo = new TrainedNinja("Leonardo", p1); 
    TrainedNinja *raphael = new TrainedNinja("Raphael", p1);
    CHECK_EQ(leonardo->getLP(), 120);
    CHECK_EQ(raphael->getSpeed(), 12);
}

TEST_CASE("Young Ninja TEST:")
{
    // Young Ninja starts with 100 LP & 14 Speed
    Point p1(0,0);
    YoungNinja *donatello = new YoungNinja("Donatello", p1); 
    YoungNinja *michelangelo = new YoungNinja("Michelangelo", p1);
    CHECK_EQ(donatello->getLP(), 100);
    CHECK_EQ(michelangelo->getSpeed(), 14);
}

TEST_CASE("Team TEST:")
{
    Point p1(0,0);
    Cowboy *good = new Cowboy("good", p1);
    Cowboy *bad = new Cowboy("bad", p1);
    Cowboy *ugly = new Cowboy("ugly", p1);
    OldNinja *splinter = new OldNinja("Splinter", p1); 
    OldNinja *shredder = new OldNinja("Shredder", p1);
    YoungNinja *donatello = new YoungNinja("Donatello", p1); 
    YoungNinja *michelangelo = new YoungNinja("Michelangelo", p1);
    TrainedNinja *leonardo = new TrainedNinja("Leonardo", p1); 
    TrainedNinja *raphael = new TrainedNinja("Raphael", p1);

    OldNinja *israel = new OldNinja("Ninja Israel", p1);
    OldNinja *grill = new OldNinja("Ninja Grill", p1);

    Team pizza(splinter);
    CHECK_THROWS(Team(splinter)); // cannot be in two other teams
    CHECK_THROWS(pizza.add(splinter)); // cannot add a member twice to the same team
    pizza.add(good).add(bad).add(ugly).add(shredder).add(donatello).add(michelangelo).add(leonardo).add(raphael); // 9 members now
    CHECK_NOTHROW(pizza.add(israel));
    // pizza team have now 10 members (limit)
    CHECK_THROWS(pizza.add(grill)); // only 10 are allowed
    CHECK_NOTHROW(pizza.print());
    // lets kill the leader
    splinter->hit(200);
    // CHECK_EQ(pizza.getLeader()->getName(), "good");

}

TEST_CASE("3 Cowboys Deals The One Ninja TEST:")
{
    Point p1(0,0), far(10000, 0);
    Cowboy *good = new Cowboy("good", p1);
    Cowboy *bad = new Cowboy("bad", p1);
    Cowboy *ugly = new Cowboy("ugly", p1);
    YoungNinja *looser = new YoungNinja("im going to lose", far);
    Team cowboys(good);
    cowboys.add(bad).add(ugly);
    Team ninjago(looser);
    // the ninja should try to attack them, but he is to far from them
    int iterCounter = 0;
    while(cowboys.stillAlive() > 0 && ninjago.stillAlive() > 0)
    {
        cowboys.attack(&ninjago);
        ninjago.attack(&cowboys);
        if (iterCounter > 10)
        {
            CHECK(1 == 2); // just throwing something because it doesnt work
            break;
        }
        iterCounter++;
    }
    // ninjago should lose without hit the cowboys
    CHECK_FALSE(looser->isAlive());
    CHECK_EQ(ninjago.stillAlive(), 0);
    CHECK_EQ(cowboys.stillAlive(), 3);
    CHECK((good->getLP() == 110) + (bad->getLP() == 110) + (ugly->getLP() == 110) == 3); // 3 true
    // CHECK_THROWS(cowboys.attack(&ninjago)); // cannot attack dead
    // CHECK_THROWS(ninjago.attack(&cowboys)); // dead cannot attack
}

TEST_CASE("One Close Ninja Can Deal With Two Close Cowboys TEST:")
{
    Point p1(0,0);
    Cowboy *good = new Cowboy("good", p1);
    Cowboy *bad = new Cowboy("bad", p1);
    OldNinja *winner = new OldNinja("im going to win", p1);
    Team cowboys(good);
    cowboys.add(bad);
    Team ninjago(winner);
    // the ninja should win this battle
    int iterCounter = 0;
    while(cowboys.stillAlive() > 0 && ninjago.stillAlive() > 0)
    {
        ninjago.attack(&cowboys); // 110 -> 70  -> 30   -> 0  -> 70 -> 30 -> 0
        cowboys.attack(&ninjago); // 150 -> 120 -> 100  -> 90 -> 80 -> 70 -> 60
        if (iterCounter > 10)
        {
            CHECK(1 == 2); // just throwing something because it doesnt work
            break;
        }
        iterCounter++;
    }
    // ninjago should win in 6 turns
    CHECK(winner->isAlive());
    CHECK_EQ(ninjago.stillAlive(), 1);
    CHECK_EQ(cowboys.stillAlive(), 0);
    CHECK_EQ(winner->getLP(), 60); 
    // CHECK_THROWS(ninjago.attack(&cowboys)); // dead cannot attack
    // CHECK_THROWS(cowboys.attack(&ninjago)); // cannot attack dead
}

TEST_CASE("The Oreder Of Attack & Leader Changes TEST:")
{
    Point p1(0,0) , far1(1000, 0), far2(1015, 0), far3(1005, 0); // far1 closer to far3 than far2
    Cowboy *cowboy1 = new Cowboy("c1", p1);
    Cowboy *cowboy2 = new Cowboy("c2", p1);
    Cowboy *cowboy3 = new Cowboy("c3", p1);
    Cowboy *cowboy4 = new Cowboy("c4", p1);
    Cowboy *cowboy5 = new Cowboy("c5", p1);

    TrainedNinja *ninja1 = new TrainedNinja("n1", far1); // start with: 120 LP & 12 Speed
    TrainedNinja *ninja2 = new TrainedNinja("n2", far2); 
    TrainedNinja *ninja3 = new TrainedNinja("n3", far3); 

    Team2 cowboys(cowboy1);
    cowboys.add(cowboy2).add(cowboy3).add(cowboy4).add(cowboy5);
    Team ninjas(ninja1);
    ninjas.add(ninja2).add(ninja3);
    CHECK_EQ(ninjas.getLeader(), static_cast<Character*>(ninja1));
    CHECK_EQ(cowboys.getLeader(), static_cast<Character*>(cowboy1));
    for (int i = 0; i < 3; i++) // 3 turns => 150 damage of shoot 
    {
        cowboys.attack(&ninjas); // should shoot at leader 
        ninjas.attack(&cowboys); // should move to leader
    }
    // the leader of ninjas should be dead now, the third ninja should take its place
    CHECK_EQ(cowboys.stillAlive(), 5);
    CHECK_EQ(ninjas.stillAlive(), 2);
    CHECK_EQ(ninjas.getLeader(), static_cast<Character*>(ninja3));
    for (int i = 0; i < 3; i++) // 3 turns => 150 more damage of shoot 
    {
        cowboys.attack(&ninjas); // should shoot at leader 
        ninjas.attack(&cowboys); // should move to leader
    }
    CHECK_EQ(cowboys.stillAlive(), 5);
    CHECK_EQ(ninjas.stillAlive(), 1);
    CHECK_EQ(ninjas.getLeader(), static_cast<Character*>(ninja2));
    CHECK_FALSE(cowboy1->hasboolets()); // since exactly 6 turns were played
}

TEST_CASE("Can A Smart Team Do What A Regular Team Cannot? TEST:")
{
    // lets put them in a specpic situation:
    Point p1(110,0), p2(100,0), p3(300,0); 
    Cowboy *cowboyA = new Cowboy("c1", p1);
    Cowboy *cowboyB = new Cowboy("c2", p3);
    cowboyA->hit(100);
    cowboyB->hit(100);
    // now they both going to die with only 10 LP
    YoungNinja *ninjaA = new YoungNinja("n1", p2);
    OldNinja *ninjaB = new OldNinja("n2", p2);
    ninjaA->hit(60);
    ninjaB->hit(110);
    // now they both going to die with only 40 LP
    Team A(cowboyA);
    Team2 B(ninjaB);
    A.add(ninjaA);
    B.add(cowboyB);
    // at this point we have tie, 2 cowboys with 10 LP, 2 ninjas with 40 LP:
    int iterCounter = 0;
    while(A.stillAlive() > 0 && B.stillAlive() > 0)
    {
        A.attack(&B); // cowboy will shoot the ninja and then ninja will slash the ninja
        B.attack(&A); // cowboy will shoot the cowboy, next turn it will shoot the ninja (after 4 turns)
        if (iterCounter > 3)
        {
            CHECK(1 == 2); // just throwing something because it doesnt work
            break;
        }
        iterCounter++;
    }
    // A could win but lost:
    CHECK_FALSE(A.stillAlive());
    CHECK(B.stillAlive());

    // now lets try again with smart team

    Cowboy *cowboyC = new Cowboy("c1", p1);
    Cowboy *cowboyD = new Cowboy("c2", p3);
    cowboyC->hit(100);
    cowboyD->hit(100);
    // now they both going to die with only 10 LP
    YoungNinja *ninjaC = new YoungNinja("n1", p2);
    OldNinja *ninjaD = new OldNinja("n2", p2);
    ninjaC->hit(60);
    ninjaD->hit(110);
    // now they both going to die with only 40 LP
    SmartTeam C(cowboyC); // SMART TEAM
    Team2 D(ninjaD);
    C.add(ninjaC);
    D.add(cowboyD);
    // at this point we have tie, 2 cowboys with 10 LP, 2 ninjas with 40 LP:
    iterCounter = 0;
    while(C.stillAlive() > 0 && D.stillAlive() > 0)
    {
        C.attack(&B); // ninja will slash the ninja, cowboy will shoot the cowboy
        D.attack(&A); // all are dead
        if (iterCounter > 3)
        {
            CHECK(1 == 2); // just throwing something because it doesnt work
            break;
        }
        iterCounter++;
    }
    // C will win because it smart 
    CHECK_FALSE(D.stillAlive());
    CHECK(C.stillAlive());
    
}