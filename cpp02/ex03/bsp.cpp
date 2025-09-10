#include "Point.hpp"
#include <iostream>

bool points_in_line(Point const a, Point const b, Point const c);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float w1;
    float w2;

    if (a==b || a==c || b==c)
    {
        std::cout << "some points are equivalent\n";
        return (0);
    }
    if (points_in_line(a, b, c))
    {
        std::cout << "points are in one line\n";
        return (0);
    }
    if (c.difY(a) == 0)
        return (bsp(b, a, c, point));
    // kdyz cy == ay, return bsp(b, a, c, point);
    w1 = (point.difX(a) * c.difY(a) - c.difX(a) * point.difY(a)) / (b.difX(a) * c.difY(a) - b.difY(a) * c.difX(a));
    w2 = (point.difY(a) - w1 * b.difY(a))/c.difY(a);
    // std::cout << "w1: " << w1 << ", w2: " << w2 <<std::endl;
    // std::cout <<"px-ax: " << point.difX(a) << " cy-ay: " << c.difY(a) <<  " times: " << point.difX(a) * c.difY(a) <<std::endl;
    return (w1 > 0 && w2 > 0 && w1 + w2 < 1);
}

bool points_in_line(Point const a, Point const b, Point const c)
{
    if (b.difY(c) == 0 && a.difY(c) == 0 )
        return 1;
    else if ((b.difY(c) == 0 && a.difY(c) != 0) || (b.difY(c) != 0 && a.difY(c) == 0))
        return 0;
    else if (b.difX(c)/b.difY(c) == a.difX(c)/a.difY(c))
        return 1;
    return 0;
}