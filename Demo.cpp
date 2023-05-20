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

#include "sources/Team.hpp" //no need for other includes
#include "sources/SmartTeam.hpp"

using namespace ariel;

int main()
{
   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   tom->shoot(sushi);
   cout << tom->print() << endl;

   sushi->move(tom);
   sushi->slash(tom);
   cout << "tom hit point : " << tom->get_hitPoints() << endl;

   Team team_A(tom);
   team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // Team b(tom); should throw tom is already in team a

   Team team_B(sushi);
   team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   Cowboy *bar = new Cowboy("Bar", a);
   //    team_A.add(bar);
   // cout << "first: " << endl;
   //   team_A.print();
   //   cout << "2: " << endl;
   //   team_A.attack(&team_B);
   //   cout << "3: " << endl;
   //   team_A.print();

   //   while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
   //      team_A.attack(&team_B);
   //      team_B.attack(&team_A);
   //      team_A.print();
   //      team_B.print();
   //   }

   cout << "bar test: ------------------------------------" << endl;
   Cowboy *c1 = new Cowboy("T2", Point(1, 1));              // 1
   YoungNinja *YNi = new YoungNinja("YN", Point(-20, -20)); // 4
   TrainedNinja *ON = new TrainedNinja("ON", Point(9, 9));  // 3
   OldNinja *TR = new OldNinja("TR", Point(0, 0));          // 2

   OldNinja *TrR = new OldNinja("Trrr", Point(32, 32)); // 2
   team_A.add(TrR);

   SmartTeam t(c1);
   t.add(YNi);
   t.add(ON);
   t.add(TR);

   int count = 0;

   while (team_A.stillAlive() > 0 && t.stillAlive() > 0)
   {
      t.attack(&team_A);
      team_A.attack(&t);
      
         cout << "t print: ------------------------------------" << endl;
   t.print();
   cout << "teamA print: ------------------------------------" << endl;
   team_A.print();
      
      count += 1;
   }
   // t.attack(&team_A);
   cout <<"count: "<< count <<endl;
      if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
      cout << "winner is t" << endl;

   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // team_A.attack(&t);
   // cout<< "my o" << endl;
   // cout <<"t is alive ? "<< t.stillAlive() << endl;
   // team_A.attack(&t);


   // cout << "t print: -------------         t print:-------------------" << endl;

   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();

   // cout << "------------------------------------ 1: ------------------------------------" << endl;

   // t.attack(&team_A);
   // cout << "t print: ------------------------------------" << endl;
   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();
   // cout << "------------------------------------ 2: ------------------------------------" << endl;
   // t.attack(&team_A);
   // cout << "t print: ------------------------------------" << endl;
   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();
   // cout << "------------------------------------ 3: ------------------------------------" << endl;
   // t.attack(&team_A);
   // cout << "t print: ------------------------------------" << endl;
   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();
   // cout << "------------------------------------ 4: ------------------------------------" << endl;
   // t.attack(&team_A);
   // cout << "t print: ------------------------------------" << endl;
   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();
   // cout << "------------------------------------ 5: ------------------------------------" << endl;
   // t.attack(&team_A);
   // cout << "t print: ------------------------------------" << endl;
   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();
   // cout << "------------------------------------ 6: ------------------------------------" << endl;
   // t.attack(&team_A);
   // cout << "t print: ------------------------------------" << endl;
   // t.print();
   // cout << "teamA print: ------------------------------------" << endl;
   // team_A.print();

   // t.attack(&team_A);
   // t.attack(&team_A);
   // t.attack(&team_A);

   // t.attack(&team_A);
   // t.attack(&team_A);

   cout << "t print: ------------------------------------" << endl;
   t.print();
   cout << "teamA print: ------------------------------------" << endl;
   team_A.print();

   //    while(t.stillAlive() > 0 && team_A.stillAlive() > 0){
   //      t.attack(&team_A);
   //      team_A.attack(&t);
   //      t.attack(&team_A);
   //      cout << "t print: ------------------------------------" << endl;
   //      t.print();
   //      cout << "teamA print: ------------------------------------" << endl;
   //      team_A.print();
   //   }

   // team_A.print();

   cout << "bar test: ------------------------------------" << endl;

   if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
      cout << "winner is team_B" << endl;

   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}
