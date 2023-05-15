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

bool compareCharacters(Character *a, Character *b)
{
    return a->get_type() < b->get_type();
}

void Team::sort_team()
{
    std::sort(_chTeam.begin(), _chTeam.end(), compareCharacters);
}

Character *Team::new_target(Team *other_team)
{
    size_t count = 0;
    int min_des = std::numeric_limits<double>::max();
    for (size_t i = 0; i < other_team->_chTeam.size(); i++)
    {
        if (other_team->_chTeam.at(i)->isAlive() && _leader->distance(other_team->_chTeam.at(i)) < min_des)
        {
            min_des = _leader->distance(other_team->_chTeam.at(i));
            count = i;
        }
    }
    Character *ans = other_team->_chTeam.at(count);
    return ans;
}

void Team::attack(Team *other_team)
{
    this->sort_team();
    if (other_team->stillAlive() < 1 || stillAlive() < 1)
    {
        throw runtime_error("one of the team is dead");
    }

    if (!(_leader->isAlive()))
    {
        double des = std::numeric_limits<double>::max();
        for (size_t i = 0; i < _chTeam.size(); i++)
        {
            if (_chTeam.at(i)->isAlive() && des > _leader->distance(_chTeam.at(i)))
            {
                des = _leader->distance(_chTeam.at(i));
                _leader = _chTeam.at(i);
            }
        }
    }

    Character *target = new_target(other_team);

    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        if (!(target->isAlive()))
        {
            target = new_target(other_team);
        }
        if (other_team->stillAlive() < 1 || stillAlive() < 1)
        {
            break;
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
            else if (Ninja *ninja = dynamic_cast<Ninja *>(_chTeam.at(i)))
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
    this->sort_team();
            for (size_t i = 0; i < _chTeam.size(); i++)
        {
            _chTeam.at(i)->print();
        }

}

Character *Team::get_leader()
{
    return _leader;
}

// Team::~Team(){
//     cout << "bar "<< endl;
// for(size_t i = 0; i < _chTeam.size(); i++){
//     delete _chTeam.at(i);
// }
// }
