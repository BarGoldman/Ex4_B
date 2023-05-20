#include "SmartTeam.hpp"
#include <limits>
#include <algorithm>

/*
The main implementation of SmartTeam:

approach is to neutralize as many members of the opposing team as possible, 
thereby reducing the number of attacks against the attacking team.

First, I sorted both the attacking and defending teams based on the hits points. 
I searched for the leader of the attacking team with the highest hit points and the 
target with the lowest hit points.

During each attack, I over the members of the attacking team. If the member is a cowboy 
they directly attack the target because their position doesn't matter.

However, if the member of the attacking team is a "Ninja," 
I first check if they can attact the target with the minimum highest hit. If not, 
I choose another target from the defending team who is closer to the Ninja than other members of the opposing team. 
This target becomes the new objective for the Ninja.
If the Ninja encounters the initially chosen target on the way to the new objective, 
they will assist their team members in neutralizing the target; 
otherwise, they continue on their path towards the new objective.

The idea came to me from Algorithms-1 course

*/

SmartTeam::SmartTeam(Character *player) : Team(player)
{
}

Character *SmartTeam::new_target(Team *other_team)
{
    Character *ans = nullptr;
    size_t i = 0;
    while (ans == nullptr && i < other_team->get_chTeam().size())
    {
        if (other_team->get_chTeam().at(i)->isAlive())
        {
             ans = other_team->get_chTeam().at(i);
        }
        i++;
    }
    return ans;
}

void SmartTeam::find_newLeader()
{
    size_t i = get_chTeam().size();
    while(!(get_leader()->isAlive()) && i  > 0){
        if (get_chTeam().at(i-1)->isAlive())
        {
            setLeader(get_chTeam().at(i-1));
        }
        i--;
    }  
}

void SmartTeam::sort_Team(Team *team) {
     std::sort(team->get_chTeam().begin(), team->get_chTeam().end(), [team](const Character* character1, const Character* character2){
        return character1->get_hitPoints() < character2->get_hitPoints();
     });
}

Character *SmartTeam::find_target_forNinja(Team *other_team, Character * ninja)
{
     double max_des = std::numeric_limits<double>::max();
     Character *ans = nullptr;
     for (size_t i = 0; i < other_team->get_chTeam().size(); i++)
     {
        if (other_team->get_chTeam().at(i)->isAlive() && ninja->distance(other_team->get_chTeam().at(i)) < max_des)
        {
            max_des = ninja->distance(other_team->get_chTeam().at(i));
            ans = other_team->get_chTeam().at(i);
        }
     }
     return ans;
}

void SmartTeam::attack(Team *other_team)
{
    if (other_team == nullptr)
    {
        throw std::invalid_argument("Sending nullptr to the attack() method");
    }
    sort_Team(this);
    sort_Team(other_team);
    if (!(other_team->stillAlive()))
    {
        throw runtime_error("other_team is dead");
    }
    if(!(stillAlive())){
        throw runtime_error("team is dead");
    }

    if (!(get_leader()->isAlive()))
    {
        find_newLeader();
    }

    Character *target = new_target(other_team);
    for (size_t i = 0; i < get_chTeam().size(); i++)
    {

        if (!(other_team->stillAlive()))
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
                if (cowboy->hasboolets())
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
                    if(other_team->stillAlive() == 1){
                        ninja->move(target);
                    }
                    else
                    {
                        Character *Ninja_target = find_target_forNinja(other_team,ninja);

                        if (ninja->distance(Ninja_target) < 1)
                        {
                            ninja->slash(Ninja_target);
                        }
                        else
                        {
                            ninja->move(Ninja_target);
                        }
                    }
                }
            }
        }
    }
}

void SmartTeam::print()
{
    sort_Team(this);
    string ans = "";
    for (size_t i = 0; i < get_chTeam().size(); i++)
    {
        ans = ans + get_chTeam().at(i)->print() + " ";
    }
    cout << ans << endl;
}