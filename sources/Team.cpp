#include "Team.hpp"
#include <limits>

Team::Team(Character *player) : _leader(player)
{
    cout << "my problem1" << endl;
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
void Team::attack(Team *other_team)
{
    // if (other_team->stillAlive() > 0 )
    // {
    //     if (stillAlive() > 0)
    //     {
    //         if (!(_leader->isAlive()))
    //         {
    //             for (size_t i = 0; i < _chTeam.size(); i++)
    //             {
    //                 double des = std::numeric_limits<double>::max();
    //                 if (_chTeam.at(i)->isAlive() && des < _leader->distance(_chTeam.at(i)))
    //                 {
    //                     _leader = _chTeam.at(i);
    //                 }
    //             }
    //         }
    //     }
    //     int count = 0;
    //     int min_des = std::numeric_limits<double>::max();
    //     for (size_t i = 0; i < other_team->_chTeam.size(); i++)
    //     {
    //         if (_leader->distance(other_team->_chTeam.at(i)) < min_des)
    //         {
    //             count = i;
    //         }
    //     }
    // }
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
void Team::print() const
{
    for (size_t i = 0; i < _chTeam.size(); i++)
    {
        _chTeam.at(i)->print();
        cout<< "i: " << i << endl;
    }
}

string Team::get_leader()
{
    return _leader->getName();
}

// Team::~Team(){
//     cout << "bar "<< endl;
// }
