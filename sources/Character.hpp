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


    int _inTeam; // 1 for cowboy 2- for Ninja

public:
    Character(string name, Point location, int hit);

    virtual ~Character(){cout<< "good dis to Character" << endl;}

    bool isAlive() const; //returns a boolean value is the character alive (that is, has more than zero hit points)
    double distance(const Character *player) const; // Returns the distance between the characters
    void hit(int num); // Gets an integer. Subtracts the appropriate amount of hit points from the character.other returns nothing.
    string getName(); // Returns the name of the character.
    Point getLocation(); // Returns the position of the character.

    
    virtual string print() const;// print in the character 
    //The function is virtual because in the group, we perform printing per Character




    //////////////////////////////// Added By Myself ////////////////////////////////
    int get_hitPoints() const;

    int get_inTeam() const{
        return _inTeam;
    }

    void set_inTeam(){
        _inTeam = 1;
    }


    void set_location(const Point& new_point);


    bool operator<(const Character& other) const ;


    // Declare the defaulted special member functions



    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    Character(Character&&) = delete;
    Character& operator=(Character&&) = delete;
};

#endif
