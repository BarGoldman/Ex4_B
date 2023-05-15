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

    double distance(const Point &point2) const;
    string print() const;

    static Point moveTowards(const Point & source, const Point & target, double dis);

    // friend ostream &operator<<(ostream &output, const Point &other);
};

#endif
