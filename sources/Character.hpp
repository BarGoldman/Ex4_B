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


    int _type; // 1 for cowboy 2- for Ninja

public:
    Character(string name, Point location, int hit, int type);

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

    int get_type(){
        return _type;
    }


    void set_location(const Point& new_point);
};

#endif
