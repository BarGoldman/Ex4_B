#include "Character.hpp"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

Character::Character(string name, Point location, int hit, int type) : _name(name), _location(location), _hitPoints(hit), _type(type)
{
}

bool Character::isAlive()
{
    return (_hitPoints > 0);
}

double Character::distance(Character *player)
{
    return _location.distance(player->_location);
}

void Character::hit(int num)
{
    if(num < 0 ){
        throw std::invalid_argument("num is negative value");
    }
    if (_hitPoints - num < 0)
    {
        _hitPoints = 0;
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


//////

int Character::get_hitPoints()
{
    return _hitPoints;
}


void Character::set_location(const Point& new_point){
    _location = new_point;
}
