#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(string name, Point location,int hit ,int speed):Character(name, location, hit),_speed(speed)
{

}

void Ninja::move(Character* enemy)
{
    Point new_p = Point::moveTowards(getLocation(),enemy->getLocation(),_speed);
    set_location(new_p);
}

void Ninja::slash(Character *enemy)
{
    if(!(enemy->isAlive()) || !(isAlive())){
        throw std::runtime_error("Attacking a dead character");
    }
    if(enemy == nullptr){
        throw std::runtime_error("No enemy");
    }
    if (enemy == &(*this))
    {
        throw std::runtime_error("No self harm");
    }
    if (this->distance(enemy) < 1)
    {
        enemy->hit(40);
    }
}

string Ninja::print() const{return "N: " +  Character::print();}
