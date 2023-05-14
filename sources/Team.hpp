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

    void add(Character* player);
    virtual void attack(Team* other_team);
    int stillAlive();
    virtual void print() const  ;



    string get_leader();


    ////
    int get_sizeTeam(){
        return _chTeam.size();
    }
};
#endif
