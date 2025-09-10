#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const Fixed& x, const Fixed& y);
        Point(const float fx, const float fy);
        Point(const int ix, const int iy);
        Point(const Point& other);
        Point& operator=(const Point& other);
        bool operator==(const Point& other) const;
        ~Point();
        float difX(const Point& p) const;
        float difY(const Point& p) const;
        void printPoint();
};


#endif