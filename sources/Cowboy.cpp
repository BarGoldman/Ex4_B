

#include "Character.hpp"
#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), _numBalls(6)
{
}

void Cowboy::shoot(Character *enemy)
{
    if (!(enemy->isAlive()) || !(isAlive()))
    {
        throw std::runtime_error("Dead character");
    }
    if (enemy == &(*this))
    {
        throw std::runtime_error("No self harm");
    }
    if (_numBalls > 0)
    {
        enemy->hit(10);
        _numBalls = _numBalls - 1;
    }
}

bool Cowboy::hasboolets() const
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

string Cowboy::print() const {
    return "C: " +  Character::print();
}

int Cowboy::get_numBalls()
{
    return _numBalls;
}