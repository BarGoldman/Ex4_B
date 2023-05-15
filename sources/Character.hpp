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
    // The same point can be set for each of the characters
    Point _location;
    int _hitPoints;

public:
    Character(string name, Point location, int hit);

    virtual ~Character(){cout<< "good dis to Character" << endl;}

    bool isAlive() const;
    double distance(const Character *player) const;
    void hit(const int num);
    string getName();
    Point getLocation();

    // print in the character
    virtual string print() const;

    //// add by me
    int get_hitPoints();


    void set_location(const Point& new_point);
};

#endif
