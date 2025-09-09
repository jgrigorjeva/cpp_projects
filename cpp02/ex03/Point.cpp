#include "Point.hpp"

Point::Point(): x(0), y(0)
{
    std::cout << "Default Point costructor called\n";
}
Point::Point(const Fixed& x, const Fixed& y): x(x), y(y)
{
    std::cout << "Parametrized Point from Fixed costructor called\n";

}
Point::Point(const float fx, const float fy): x(fx), y(fy)
{
    std::cout << "Parametrized Point from float costructor called\n";
}
Point::Point(int ix, int iy): x(ix), y(iy)
{
    std::cout << "Parametrized Point from int costructor called\n";
}

Point::~Point() {std::cout << "Point destructor called\n";}

Point::Point(const Point &other): x(other.x), y(other.y)
{
	std::cout << "Copy costructor called\n";
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->x = other.x; 
        this->y = other.y;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}