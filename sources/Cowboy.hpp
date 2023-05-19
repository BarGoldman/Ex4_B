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
    ~Cowboy()override{cout<< "good dis to Cowboy" << endl;};


    //If the Cowboy is not dead and has bullets left,     
    //the morning shoots the enemy, subtracting 10 hit points from the enemy - and losing 1 bullet. 
    //Otherwise, no damage will be done to the enemy.
    void shoot(Character *enemy); 

    // Checking the cartridge hasboolets() returns a Boolean indicating whether 
    // there are any bullets left in this morning's gun.
    bool hasboolets() const;
    void reload(); // Loads the gun with six new bullets.


    string print() const override;


    Cowboy(const Cowboy&) = delete;
    Cowboy& operator=(const Cowboy&) = delete;
    Cowboy(Cowboy&&) = delete;
    Cowboy& operator=(Cowboy&&) = delete;
};

#endif