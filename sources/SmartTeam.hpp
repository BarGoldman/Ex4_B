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

    void print() override;
    void attack(Team* other_team) override;


    Character* new_target(Team *other_team) override;
    void find_newLeader() override;
    // bool compareCharacters(Character* character1,Character *character2);


    void sort_Team(Team *team);


    SmartTeam(const SmartTeam&) = delete;
    SmartTeam& operator=(const SmartTeam&) = delete;
    SmartTeam(SmartTeam&&) = delete;
    SmartTeam& operator=(SmartTeam&&) = delete;
};
#endif
