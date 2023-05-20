#include "Team2.hpp"
#include <limits>

Character *Team2::new_target(Team *other_team)
{
    double max_des = std::numeric_limits<double>::max();
    Character *ans = nullptr;
    for (size_t i = 0; i < other_team->get_chTeam().size(); i++)
    {
        if (other_team->get_chTeam().at(i)->isAlive() && get_leader()->distance(other_team->get_chTeam().at(i)) < max_des)
        {
            max_des = get_leader()->distance(other_team->get_chTeam().at(i));
            ans = other_team->get_chTeam().at(i);
        }
    }
    return ans;
}

void Team2::find_newLeader()
{
    double des = std::numeric_limits<double>::max();
    size_t count = 0;
    for (size_t i = 0; i < get_chTeam().size(); i++)
    {
        if (get_chTeam().at(i)->isAlive() && des > get_leader()->distance(get_chTeam().at(i)))
        {
            des = get_leader()->distance(get_chTeam().at(i));
            count = i;
        }
    }
    setLeader(get_chTeam().at(count));
}

void Team2::attack(Team *other_team)
{
    if (other_team == nullptr)
    {
        throw std::invalid_argument("Sending nullptr to the attack() method");
    }
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
                    ninja->move(target);
                }
            }
        }
    }
}

void Team2::print()
{
    string ans = "";
    for (size_t i = 0; i < get_chTeam().size(); i++)
    {
        ans = ans + get_chTeam().at(i)->print() + " ";
    }
}