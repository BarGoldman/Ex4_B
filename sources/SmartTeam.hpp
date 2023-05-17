#ifndef ST_H
#define ST_H

#include "Team.hpp"


namespace ariel
{
};

class SmartTeam : public Team
{
public:
    SmartTeam(Character* player):Team(player){};
    ~SmartTeam()override{};

    void print() override;
    void attack(Team* other_team) override;


    Character* new_target(Team *other_team) override;
    void find_newLeader() override;



    SmartTeam(const SmartTeam&) = delete;
    SmartTeam& operator=(const SmartTeam&) = delete;
    SmartTeam(SmartTeam&&) = delete;
    SmartTeam& operator=(SmartTeam&&) = delete;
};
#endif
