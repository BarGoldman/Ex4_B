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
    ~Team2(){};

    void print();

    void attack(Team* other_team) override;
};
#endif

