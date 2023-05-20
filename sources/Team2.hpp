#ifndef T2_H
#define T2_H

#include "Team.hpp"

namespace ariel
{
};

class Team2 : public Team
{
public:
    Team2(Character* player):Team(player){}
    ~Team2() override {};

    void attack(Team* other_team) override;
    void print() override;

    //////////////////////////////// Added By Myself ////////////////////////////////

    Character* new_target(Team *other_team) override;
    void find_newLeader() override;

    //////////////////////////////// for distrctor ////////////////////////////////
    Team2(const Team2&) = delete;
    Team2& operator=(const Team2&) = delete;
    Team2(Team2&&) = delete;
    Team2& operator=(Team2&&) = delete;
};
#endif

