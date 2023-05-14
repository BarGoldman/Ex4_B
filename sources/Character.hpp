#ifndef CH_H
#define CH_H

#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{
};

class Character
{
private:
    string _name;
    Point _location;
    int _hitPoints;

    int _type; // 1 - for Ninja  , 2 - for Cowboy

public:
    Character(string name, Point location, int hit, int type);
    // ~Character(){cout<< "good dis to Character" << endl;}

    bool isAlive();
    double distance(Character *player);
    void hit(int num);
    string getName();
    Point getLocation();
    string print();

    //// add by me
    int get_hitPoints();

    void set_location(const Point& new_point);
};

#endif
