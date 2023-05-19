#include "Team.hpp"
#include <limits>
#include <algorithm>

Team::Team(Character *player) : _leader(player)
{
    if (player == nullptr)
    {
        throw std::invalid_argument("you try to add null player");
    }
    if (player->get_inTeam() == 1)
    {
        throw std::runtime_error("Appointing the same captain to different teams");
    }
    add(player);
}

void Team::add(Character *player)
{
    if (_chTeam.size() >= 10)
    {
        throw std::runtime_error("A team can have at most 10 teammates");
    }
    if (player->get_inTeam() == 1)
    {
        throw std::runtime_error("Adding the same character to different teams");
    }
    _chTeam.push_back(player);
    player->set_inTeam();
}

Character *Team::new_target(Team *other_team)
{
    double max_des = std::numeric_limits<double>::max();
    Character *ans = nullptr;
    for (size_t i = 0; i < other_team->_chTeam.size(); i++)
    {
        if (other_team->_chTeam.at(i)->isAlive() && _leader->distance(other_team->_chTeam.at(i)) < max_des)
        {

            max_des = _leader->distance(other_team->_chTeam.at(i));
            ans = other_team->_chTeam.at(i);
        }
    }
    return ans;
}

void Team::find_newLeader()
{
    double des = std::numeric_limits<double>::max();
    size_t count = 0;
    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        if (_chTeam.at(i)->isAlive() && des > _leader->distance(_chTeam.at(i)))
        {
            des = _leader->distance(_chTeam.at(i));
            count = i;
        }
    }
    _leader = _chTeam.at(count);
}

void Team::attack(Team *other_team)
{
    if (other_team == nullptr)
    {
        throw std::invalid_argument("Sending nullptr to the attack() method");
    }

    if (other_team->stillAlive() < 1 || stillAlive() < 1)
    {
        throw runtime_error("one of the team is dead");
    }

    if (!(_leader->isAlive()))
    {
        find_newLeader();
    }

    Character *target = new_target(other_team);
    for (size_t i = 0; i < _chTeam.size(); i++)
    {

        if (other_team->stillAlive() < 1 || stillAlive() < 1)
        {
            break;
        }
        if (!(_leader->isAlive()))
        {

            find_newLeader();
        }

        if (!(target->isAlive()))
        {
            target = new_target(other_team);
        }

        if (_chTeam.at(i)->isAlive())
        {
            // The cast allows you to convert a pointer of one type to a pointer of another type,
            // and checks the correctness of the cast at runtime. If the cast is possible,
            // it will return the instantiated pointer to the requested type.
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(_chTeam.at(i)))
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
        }
    }
    for (size_t i = 0; i < _chTeam.size(); i++)
    {

        if (other_team->stillAlive() < 1 || stillAlive() < 1)
        {
            break;
        }
        if (!(_leader->isAlive()))
        {

            find_newLeader();
        }

        if (!(target->isAlive()))
        {
            target = new_target(other_team);
        }

        if (_chTeam.at(i)->isAlive())
        {
            // The cast allows you to convert a pointer of one type to a pointer of another type,
            // and checks the correctness of the cast at runtime. If the cast is possible,
            // it will return the instantiated pointer to the requested type.
            if (Ninja *ninja = dynamic_cast<Ninja *>(_chTeam.at(i)))
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

int Team::stillAlive()
{
    int ans = 0;
    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        if (_chTeam.at(i)->isAlive())
        {
            ans++;
        }
    }
    return ans;
}

void Team::print()
{
    string ans = "";
    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(_chTeam.at(i)))
        {
            ans = ans + cowboy->print() + " ,";
        }
        else if (Ninja *ninja = dynamic_cast<Ninja *>(_chTeam.at(i)))
        {
            ans = ans + ninja->print() + " ,";
        }
    }
    cout << ans << endl;
}

Character *Team::get_leader() const
{
    return _leader;
}

// Getter for _chTeam
const vector<Character *> &Team::get_chTeam() const
{
    return _chTeam;
}

// Setter for _chTeam
void Team::set_chTeam(const vector<Character *> &chTeam)
{
    _chTeam = chTeam;
}

// Setter for _leader
void Team::setLeader(Character *leader)
{
    _leader = leader;
}

// Team::~Team(){
//     cout << "bar "<< endl;
// for(size_t i = 0; i < _chTeam.size(); i++){
//     delete _chTeam.at(i);
// }
// }
