#include "SmartTeam.hpp"
#include <limits>
#include <algorithm>

/*
Attack - The attacking team will choose a target with a minimal number of hit points each time.
The goal is to silence the opposing team by eliminating weak players,
thereby reducing the number of players who can attack them back (an algorithm idea from Algorithms 1 course).

Choosing a leader for the team - Each time the leader is no longer alive,
the leader with the highest impact points in the group will be selected.
This ensures that we have a strong and resilient leader who will protect the team members."

Printing according to hit points.


*/

SmartTeam::SmartTeam(Character *player) : Team(player)
{
}

void SmartTeam::print()
{
    sort_Team();
    string ans = "";
    for (size_t i = 0; i < get_chTeam().size(); i++)
    {
        ans = ans + get_chTeam().at(i)->print() + " ";
    }
}

bool compareCharacters(Character* character1,Character *character2)
{
    return character1->get_hitPoints() < character2->get_hitPoints();
}

void SmartTeam::sort_Team(){
    //std::__sort(get_chTeam().begin(), get_chTeam().end(), compareCharacters);
}

void SmartTeam::attack(Team *other_team)
{
            if(other_team == nullptr){
        throw std::invalid_argument("Sending nullptr to the attack() method");
    }
    sort_Team();
    if (other_team->stillAlive() < 1 || stillAlive() < 1)
    {
        throw runtime_error("one of the team is dead");
    }

    if (!(get_leader()->isAlive()))
    {
        find_newLeader();
    }

    Character *target = new_target(other_team);
    for (size_t i = 0; i < get_chTeam().size(); i++)
    {

        if (other_team->stillAlive() < 1 || stillAlive() < 1)
        {
            break;
        }
        if (!(get_leader()->isAlive()))
        {

            find_newLeader();
        }

        if (!(target->isAlive()))
        {
            target = new_target(other_team);
        }

        if (get_chTeam().at(i)->isAlive())
        {
            // The cast allows you to convert a pointer of one type to a pointer of another type,
            // and checks the correctness of the cast at runtime. If the cast is possible,
            // it will return the instantiated pointer to the requested type.
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(get_chTeam().at(i)))
            {
                if (cowboy->get_numBalls() > 0)
                {

                    cowboy->shoot(target);
                }
                else
                {
                    cowboy->reload();
                }
            }
            else if (Ninja *ninja = dynamic_cast<Ninja *>(get_chTeam().at(i)))
            {
                if (ninja->distance(target) < 1)
                {
                    ninja->slash(target);
                }
                else
                {
                    ninja->move(target);
                }
            }
        }
    }
}

Character *SmartTeam::new_target(Team *other_team)
{
    double max_des = std::numeric_limits<double>::max();
    Character *ans = nullptr;
    for (size_t i = 0; i < other_team->get_chTeam().size(); i++)
    {
        if (other_team->get_chTeam().at(i)->isAlive() && other_team->get_chTeam().at(i)->get_hitPoints() < max_des)
        {

            max_des = other_team->get_chTeam().at(i)->get_hitPoints();
            ans = other_team->get_chTeam().at(i);
        }
    }
    return ans;
}
void SmartTeam::find_newLeader()
{
    double des = std::numeric_limits<double>::min();
    for (size_t i = get_chTeam().size() ; i > 0 ; i--)
    {
        if (get_chTeam().at(i-1)->isAlive() && des < get_chTeam().at(i-1)->get_hitPoints())
        {
            des = get_chTeam().at(i-1)->get_hitPoints();
            setLeader(get_chTeam().at(i-1));
        }
    }
}