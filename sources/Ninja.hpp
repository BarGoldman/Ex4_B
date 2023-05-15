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
    ~Ninja(){cout<< "good dis to Ninja" << endl;}

    void move(Character *enemy);
    void slash(Character *enemy);

    string print() const;

    ///
    int get_speed();
};
#endif
