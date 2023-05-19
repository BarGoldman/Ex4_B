#include "Character.hpp"
using namespace std;

Character::Character(string name, Point location, int hit) : _name(name), _location(location), _hitPoints(hit) ,_inTeam(0)
{
}

bool Character::isAlive() const
{
    return (_hitPoints > 0);
}

double Character::distance(const Character *player) const
{
    return _location.distance(player->_location);
}

void Character::hit(int num)
{
    if (num < 0)
    {
        throw std::invalid_argument("num is negative value");
    }
    else
    {
        _hitPoints = _hitPoints - num;
    }
}

string Character::getName()
{
    return _name;
}

Point Character::getLocation()
{
    return _location;
}

string Character::print() const{
    string ans = "";
    if (!(isAlive()))
    {
        ans = " Name: (" + _name + ") Location:" + _location.print();
    }
    else{
        ans = " Name: " + _name + " Num Of Hit Point: " + to_string(_hitPoints) + " Location: " + _location.print();
    }
    return ans;
}

//////////////////////////////// Added By Myself ////////////////////////////////

int Character::get_hitPoints() const
{
    return _hitPoints;
}

int Character::get_inTeam() const
{
    return _inTeam;
}

void Character::set_inTeam()
{
    _inTeam = 1;
}

void Character::set_location(const Point &new_point)
{
    _location = new_point;
}









bool Character::operator<(const Character& other) const {
    return(_hitPoints < other._hitPoints);
}


