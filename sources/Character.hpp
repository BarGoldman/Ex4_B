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


    int _inTeam; // 1 if he in team

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
    int get_hitPoints() const; // return the player hit Points

    int get_inTeam() const; // return 1 - if player in Team , 0 - if He has not joined the group yet
    
    void set_inTeam();// Updates 1 to the ingroup if he joined the group
    
    void set_location(const Point& new_point); // Updates the player's location





    bool operator<(const Character& other) const ; 

    // Declare the defaulted special member functions

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    Character(Character&&) = delete;
    Character& operator=(Character&&) = delete;
};

#endif
