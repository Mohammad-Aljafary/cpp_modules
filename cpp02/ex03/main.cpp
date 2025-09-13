#include "Point.hpp"

int main( void ) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point point(2, 1);

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle." << std::endl;
    else
        std::cout << "Point is outside the triangle." << std::endl;

    return 0;
}
