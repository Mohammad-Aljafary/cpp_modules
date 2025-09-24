#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed(): fixedPoint(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj){
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::Fixed(const float fixed){
    std::cout << "Float constructor called" << std::endl;
    fixedPoint = static_cast<int>(roundf(fixed * (1 << fraction)));
}

Fixed::Fixed(const int fixed){
    std::cout << "Int constructor called" << std::endl;
    fixedPoint = fixed * (1 << fraction);
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->fixedPoint = obj.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    fixedPoint = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" <<std::endl;
}

float Fixed::toFloat( void ) const {
    return (fixedPoint) / (1.0f * (1 << fraction));
}

int Fixed::toInt( void ) const {
    return fixedPoint / (1 << fraction);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}
