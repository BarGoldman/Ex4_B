#include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace std;


Point::Point(double x_cd , double y_cd):_x(x_cd) , _y(y_cd)
{
}


double Point::distance(const Point &point2)const
{
    double a = _x - point2._x;
    double b = _y - point2._y;
    return sqrt(pow(a, 2) + pow(b, 2));
}
void Point::print()
{
    cout << '(' << _x << ',' << _y << ')' << endl;
}

Point Point::moveTowards(const Point &source,  const Point &target, double dis)
{
    if(dis < 0){
        throw("dis is a negtiv num");
    }
    double dis_test = source.distance(target);
    if(dis_test <= dis){
        return target;
    }
    double m = (source._y - target._y)  / (source._x - target._x);
    return Point(1,2);
}

ostream &operator<<(ostream &output, const Point &other)
{
    return (output << '(' << other._x << ',' << other._y << ')');
}