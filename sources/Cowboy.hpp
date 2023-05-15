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
    ~Cowboy(){cout<< "good dis to Cowboy" << endl;};

    void shoot(Character *enemy);
    bool hasboolets() const;
    void reload();
    string print() const;

    ////
    int get_numBalls();
};

#endif