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

    virtual ~Team(){cout<< "good dis to team" << endl;}

    void add(Character* player);
    virtual void attack(Team* other_team);
    int stillAlive();
    virtual void print() const;


    //////////// add by me
    Character* get_leader();
    virtual void sort_team();
    Character* Team::new_target(Team *other_team);




    Team(const Team&) = delete;
    Team& operator=(const Team&) = delete;
    Team(Team&&) = delete;
    Team& operator=(Team&&) = delete;


};
#endif
