#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
    Point a(Fixed(0), Fixed(0));
    Point b(0.512f, 2.013f);
    Point c(2.0f, 0.0f);
    Point point_outside(3, 3);

    std::cout << "***special cases***\n";
    std::cout << "not a triangle: [0,0] [0,1] [0,2]\n";
    std::cout << "bsp: " << bsp (Point(0,0), Point(0,1), Point(0,2), Point(3,3)) << std::endl;
    std::cout << "not a triangle: [0,1] [0,1] [0,2]\n";
    std::cout << "bsp: " << bsp (Point(0,1), Point(0,1), Point(0,2), Point(3,3)) << std::endl;
    std::cout << "not a triangle: [0,0] [1,1] [2,2]\n";
    std::cout << "bsp: " << bsp (Point(0,0), Point(1,1), Point(2,2), Point(3,3)) << std::endl;
    std::cout << "not a triangle: [1,1] [0,0] [2,2]\n";
    std::cout << "bsp: " << bsp ( Point(1,1), Point(0,0), Point(2,2), Point(3,3)) << std::endl;

    std::cout << "Now a proper triangle: ";
    a.printPoint(); b.printPoint(); c.printPoint();

    std::cout << "\n point outside:\n "; point_outside.printPoint();
    std::cout << "bsp: " << bsp(a, b, c, point_outside) << std::endl;

    std::cout << "\n point outside:\n "; Point(3, 0).printPoint();
    std::cout << "bsp: " << bsp(a, b, c, Point(3, 0)) << std::endl;

    std::cout << "\n point on the vertex:\n "; Point(0, 0).printPoint();
    std::cout << "bsp: " << bsp(a, b, c, Point(0,0)) << std::endl;

    std::cout << "\n point on the side:\n "; Point(0.0f, 0.5f ).printPoint();
    std::cout << "bsp: " << bsp(a, b, c, Point(0.0f, 0.5f )) << std::endl;
    // std::cout << bsp(a, b, c, Point(-1,0)) << std::endl;

    std::cout << "Finally, some points inside\n ";
    Point(0.5f, 0.5f).printPoint();
    std::cout << "bsp: " << bsp(a, b, c, Point(0.5f, 0.5f)) << "\n ";
    Point(0.511719f, 1.98f).printPoint();
    std::cout << "bsp: " << bsp(a, b, c, Point(0.511719f, 1.98f)) << std::endl;
}