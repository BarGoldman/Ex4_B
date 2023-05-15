

#include "Character.hpp"
#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110, 2), _numBalls(6)
{
}

void Cowboy::shoot(Character *enemy)
{
    if (!(enemy->isAlive()) || !(isAlive()))
    {
        throw std::runtime_error("Attacking a dead character");
    }
    if (enemy == &(*this))
    {
        throw std::runtime_error("No self harm");
    }
    if (isAlive() && _numBalls > 0)
    {
        enemy->hit(10);
        _numBalls = _numBalls - 1;
    }
}
bool Cowboy::hasboolets()
{
    return (_numBalls > 0);
}
void Cowboy::reload()
{
    if (!(isAlive()))
    {
        throw std::runtime_error("Dead cowboy can not reload");
    }
    _numBalls = 6;
}

int Cowboy::get_numBalls()
{
    return _numBalls;
}

string Cowboy::print() const {return "h";}

//     string Character::print()
// {
//     if (_type == 1)
//     {
//         cout << "N ";
//     }
//     else if (_type == 2)
//     {
//         cout << "C ";
//     }
//     if (isAlive() == true)
//     {
//         cout << "Name: " << _name << " Num Of Hit Point: " << _hitPoints << " Location: " << _location;
//     }
//     if (isAlive() == false)
//     {
//         cout << " Name: (" << _name << ")"<< " Location: " << _location;
//     }
//     return "h";
// }
