#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
namespace ariel
{
};

class Point
{
private:
    double _x;
    double _y;

public:
    Point(double x_cd, double y_cd);

    // distance receives a point and calculates the distance between the two points:
    double distance(const Point &point2) const;

    // Print print prints the two coordinates between brackets:
    string print() const;

    //moveTowards gets a source point, a destination point and a distance. 
    // The function returns the closest point to the destination point,
    //- which is at most the given distance from the source point
    static Point moveTowards(const Point & source, const Point & target, double dis);


    // A static member function is a function that belongs to the class itself rather than an instance of the class. 
    // It can be called without creating an object of the class.

};

#endif
