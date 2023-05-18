/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

// #include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

   cout << "**** MY DEMO ******" << endl << endl;
   Cowboy *team_c1 = new Cowboy("Tom", Point(0, 0));
   Cowboy *team2_c1 = new Cowboy("fax", Point(-2, 0));
   Cowboy *team_c2 = new Cowboy("zax", Point(-3, 0));
   Cowboy *team2_c2 = new Cowboy("tin", Point(1, 0));//
   Cowboy *team2_c3 = new Cowboy("tan", Point(3, 0));//
   Cowboy *team_c3 = new Cowboy("fix", Point(5, 0));//
   Cowboy *team2_c4 = new Cowboy("fox", Point(-5, 0));

   Team team1{team_c1};
   team1.add(team_c2);
   team1.add(team_c3);
   Team2 team2{team2_c2};
   team2.add(team2_c1);
   team2.add(team2_c3);
   team2.add(team2_c4);

   for (int i = 0; i < 4; i++)
   {
      team1.attack(&team2);
      team2.print();
      cout << endl;
   }
   


     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}