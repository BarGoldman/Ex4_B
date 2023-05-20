#ifndef N_H
#define N_H

#include "Character.hpp"
using namespace std;

namespace ariel
{
};

class Ninja : public Character
{
private:
    int _speed;

public:
    Ninja(string name, Point location, int hit, int speed);

    void move(Character *enemy); // advancing towards the enemy. The ninja advances a distance equal to its speed.
    void slash(Character *enemy); // If the ninja is alive and the enemy is less than 1 meter away, the ninja will deal 40 damage to the enemy. 
                                    //Otherwise, no damage will be done to the enemy.

    string print() const override;
};
#endif
