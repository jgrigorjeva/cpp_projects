#include "Point.hpp"

Point::Point(): x(0), y(0)
{
    // std::cout << "Default Point costructor called\n";
}
Point::Point(const Fixed& x, const Fixed& y): x(x), y(y)
{
    // std::cout << "Parametrized Point from Fixed costructor called\n";

}
Point::Point(const float fx, const float fy): x(fx), y(fy)
{
    // std::cout << "Parametrized Point from float costructor called\n";
}
Point::Point(int ix, int iy): x(ix), y(iy)
{
    // std::cout << "Parametrized Point from int costructor called\n";
}

Point::~Point() {
    // std::cout << "Point destructor called\n";
}

Point::Point(const Point &other): x(other.x), y(other.y)
{
	// std::cout << "Copy costructor called\n";
}

Point &Point::operator = (const Point &src) //this thing is deceiving since you cannot reasign const attributes. So the '=' can be used without complains, but won't change anything
{
	(void)src;
	return *this;
}

bool Point::operator==(const Point& other) const
{
	return (this->x == other.x && this->y == other.y);
}

float Point::difX(const Point& p) const
{
    float difX = (this->x).toFloat() - (p.x).toFloat();
    return difX;
}

float Point::difY(const Point& p) const
{
    float difY = (this->y).toFloat() - (p.y).toFloat();
    return difY;
}

void Point::printPoint()
{
    std::cout << "[" << this->x << ", " << this->y << "] ";
}


// std::ostream& operator<<(std::ostream& out, const Fixed& src)
// {
// 	out << src.toFloat();
// 	return out;
// }