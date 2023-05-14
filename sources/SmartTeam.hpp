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

    void print();
    void attack(Team* other_team) override;



    SmartTeam(const SmartTeam&) = delete;
    SmartTeam& operator=(const SmartTeam&) = delete;
    SmartTeam(SmartTeam&&) = delete;
    SmartTeam& operator=(SmartTeam&&) = delete;
};
#endif
