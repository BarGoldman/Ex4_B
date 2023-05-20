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
    if (other_team->stillAlive() < 1 || stillAlive() < 1)
    {
        throw runtime_error("one of the team is dead");
        return;
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
                if (cowboy->hasboolets())
                {
                    cout << "shoot: " << target->getName() << endl;
                    cowboy->shoot(target);
                }
                else
                {
                    cout << "reload: " << target->getName() << endl;
                    cowboy->reload();
                }
            }
            else if (Ninja *ninja = dynamic_cast<Ninja *>(get_chTeam().at(i)))
            {
                if (ninja->distance(target) < 1)
                {
                    cout << "slash the real target: " << target->getName() << endl;
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
                            cout << "slash: " << Ninja_target->getName() << endl;
                            ninja->slash(Ninja_target);
                        }
                        else
                        {

                            cout << "try to go: " << Ninja_target->getName() << endl;
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