#ifndef TEAM_H
#define TEAM_H


#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"


#include <vector>
using namespace std;
namespace ariel
{
};

class Team
{
private:
    
    vector<Character* > _chTeam;
    Character* _leader;

public:
    Team(Character* player);

    virtual ~Team();

    void add(Character* player); // add Character to team
    virtual void attack(Team* other_team); 
    int stillAlive(); // Returns an integer number of surviving group members
    virtual void print(); // print group members 

    //////////////////////////////// Added By Myself ////////////////////////////////

    virtual Character* new_target(Team *other_team);
    virtual void find_newLeader();
    
    Character* get_leader() const;     // get  _leader  
    void setLeader(Character* leader);    // Set _leader    
    
    vector<Character*>& get_chTeam(); // get _chTeam









    Team(const Team&) = delete;
    Team& operator=(const Team&) = delete;
    Team(Team&&) = delete;
    Team& operator=(Team&&) = delete;


};
#endif
