#include "Point.hpp"
#include "Character.hpp"
#include <cmath>
#include <iostream>
using namespace std;


Point::Point(double x_cd , double y_cd):_x(x_cd) , _y(y_cd)
{
}


double Point::distance(const Point &point2) const
{
    double a = _x - point2._x;
    double b = _y - point2._y;
    return sqrt(pow(a, 2) + pow(b, 2));
}

string Point::print() const
{
    string ans = "";
    ans = '(' + _x + ',' + _y + ')';
    return ans;
}

// In this part I asked the main group of the course how the function should be calculated
Point Point::moveTowards(const Point &source,  const Point &target, double dis)
{
    if(dis < 0){
        throw std::invalid_argument("distance is a negtiv num");
    }
    double dis_test = source.distance(target);
    if(dis_test <= dis){
        return target;
    }

    //Find a unit vector in the direction from A to B,
    double unit_V_x = (target._x - source._x) / dis_test;
    double unit_V_y = (target._y - source._y) / dis_test;

    // multiply it in the dis range that the function accepts
    double new_x = unit_V_x * dis;
    double new_y = unit_V_y * dis;

    // add the vector to point A
    return Point(new_x + source._x , new_y + source._y);


    // double r = dis / dis_test;
    // double new_x = (1 - r) * source._x + r * target._x;
    // double new_y = (1 - r) * source._y + r * target._y;
    // return Point(new_x,new_y);
}

// ostream &operator<<(ostream &output, const Point &other)
// {
//     return (output << '(' << other._x << ',' << other._y << ')');
// }