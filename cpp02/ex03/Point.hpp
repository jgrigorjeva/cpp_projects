#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Point();
        Point(const Fixed& x, const Fixed& y);
        Point(const float fx, const float fy);
        Point(const int ix, const int iy);
        Point(const Point &other);
        ~Point();
};

#endif