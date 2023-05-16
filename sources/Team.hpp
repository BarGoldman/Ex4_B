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
    virtual void print();

    //////////// add by me
    virtual Character* get_leader();
    virtual Character* new_target(Team *other_team);
    virtual void Team::find_newLeader();

    // Getter for _chTeam
    const vector<Character*>& getChTeam() const;

    // Setter for _chTeam
    void setChTeam(const vector<Character*>& chTeam);

    // Getter for _leader
    Character* getLeader() const;

    // Setter for _leader
    void setLeader(Character* leader);


    void find_newLeader();




    Team(const Team&) = delete;
    Team& operator=(const Team&) = delete;
    Team(Team&&) = delete;
    Team& operator=(Team&&) = delete;


};
#endif
