#ifndef COWBOY_H
#define COWBOY_H

#include "Character.hpp"
#include <string>
using namespace std;

namespace ariel
{
};

class Cowboy : public Character
{
private:
    int _numBalls;

public:
    Cowboy(string name, Point location);

    void shoot(Character *enemy);
    bool hasboolets();
    void reload();

    ////
    int get_numBalls();
};

#endif