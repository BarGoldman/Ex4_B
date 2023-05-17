#include "Team.hpp"
#include <limits>
#include <algorithm>

Team::Team(Character *player) : _leader(player)
{
    add(player);
}

void Team::add(Character *player)
{
    if (_chTeam.size() >= 10)
    {
        throw std::runtime_error("A team can have at most 10 teammates");
    }
    _chTeam.push_back(player);
}

Character *Team::new_target(Team *other_team)
{
    double max_des = std::numeric_limits<double>::max();
    Character *ans = nullptr;
    for (size_t i = 0; i < other_team->_chTeam.size(); i++)
    {
        if (other_team->_chTeam.at(i)->isAlive() && _leader->distance(other_team->_chTeam.at(i)) < max_des)
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(other_team->_chTeam.at(i)))
            {
                max_des = _leader->distance(other_team->_chTeam.at(i));
                ans = other_team->_chTeam.at(i);
            }
        }
    }
    for (size_t i = 0; i < other_team->_chTeam.size(); i++)
    {
        if (other_team->_chTeam.at(i)->isAlive() && _leader->distance(other_team->_chTeam.at(i)) < max_des)
        {
            if (Ninja *ninja = dynamic_cast<Ninja *>(other_team->_chTeam.at(i)))
            {
                max_des = _leader->distance(other_team->_chTeam.at(i));
                ans = other_team->_chTeam.at(i);
            }
        }
    }
    return ans;
}

void Team::find_newLeader()
{
    double des = std::numeric_limits<double>::max();
    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        if (_chTeam.at(i)->isAlive() && des > _leader->distance(_chTeam.at(i)))
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(_chTeam.at(i)))
            {
                des = _leader->distance(_chTeam.at(i));
                _leader = _chTeam.at(i);
            }
        }
    }
    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        if (_chTeam.at(i)->isAlive() && des > _leader->distance(_chTeam.at(i)))
        {
            if (Ninja *ninja = dynamic_cast<Ninja *>(_chTeam.at(i)))
            {
                des = _leader->distance(_chTeam.at(i));
                _leader = _chTeam.at(i);
            }
        }
    }
}

void Team::attack(Team *other_team)
{

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
                    cout << "reload" << endl;
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
                    cout << "slash" << endl;
                    ninja->slash(target);
                }
                else
                {
                    cout << "move" << endl;
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
