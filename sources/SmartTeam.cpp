#include "SmartTeam.hpp"
#include <limits>



/*
Attack - The attacking team will choose a target with a minimal number of hit points each time. 
The goal is to silence the opposing team by eliminating weak players, 
thereby reducing the number of players who can attack them back (an algorithm idea from Algorithms 1 course).

Choosing a leader for the team - Each time the leader is no longer alive, 
the leader with the highest impact points in the group will be selected. 
This ensures that we have a strong and resilient leader who will protect the team members."
*/

void SmartTeam::print()
{
}

void SmartTeam::attack(Team *other_team)
{
}

Character *SmartTeam::new_target(Team *other_team)
{
    double max_des = std::numeric_limits<double>::max();
    Character *ans = nullptr;
    for (size_t i = 0; i < other_team->getChTeam().size(); i++)
    {
        if (other_team->getChTeam().at(i)->isAlive() && other_team->getChTeam().at(i)->get_hitPoints() < max_des)
        {

            max_des = other_team->getChTeam().at(i)->get_hitPoints();
            ans = other_team->getChTeam().at(i);
        }
    }
    return ans;
}
void SmartTeam::find_newLeader()
{
        double des = std::numeric_limits<double>::max();
    for (size_t i = 0; i < getChTeam().size(); i++)
    {
        if (getChTeam().at(i)->isAlive() && des > get_leader()->distance(getChTeam().at(i)))
        {
                des = get_leader()->distance(getChTeam().at(i));
                setLeader(getChTeam().at(i));
            
        }
    }
}