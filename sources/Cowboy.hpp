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

    void shoot(Character *enemy);
    bool hasboolets() const;
    void reload();
    string print() const override;

    ////
    int get_numBalls();


        Cowboy(const Cowboy&) = delete;
    Cowboy& operator=(const Cowboy&) = delete;
    Cowboy(Cowboy&&) = delete;
    Cowboy& operator=(Cowboy&&) = delete;
};

#endif