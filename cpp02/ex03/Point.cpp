#include "Point.hpp"

/*****************constructors********************/

Point::Point(): x(0), y(0){
}

Point::Point(const float x, const float y): x(x), y(y){
}

Point::Point(const Point& other): x(other.x), y(other.y){
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        // Since x and y are const, we cannot assign to them.
        // This operator= is effectively a no-op.
        // Alternatively, we could throw an exception or handle it differently.
    }
    return *this;
}

/**********get functions***************/

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

/*********destructor***********/

Point::~Point(){
}

