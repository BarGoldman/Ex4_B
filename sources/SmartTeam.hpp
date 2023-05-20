#ifndef ST_H
#define ST_H

#include "Team.hpp"


namespace ariel
{
};

class SmartTeam : public Team
{
public:
    SmartTeam(Character* player);
    ~SmartTeam()override{};

    
    void attack(Team* other_team) override;
    void print() override;

    //////////////////////////////// Added By Myself ////////////////////////////////

    Character* new_target(Team *other_team) override;
    void find_newLeader() override;
    void sort_Team(Team *team);
    Character* find_target_forNinja(Team *other_team,Character * ninja);

    //////////////////////////////// for distrctor ////////////////////////////////
    SmartTeam(const SmartTeam&) = delete;
    SmartTeam& operator=(const SmartTeam&) = delete;
    SmartTeam(SmartTeam&&) = delete;
    SmartTeam& operator=(SmartTeam&&) = delete;
};
#endif
