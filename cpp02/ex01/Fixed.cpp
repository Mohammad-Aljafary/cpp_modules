#include "Fixed.hpp"

const int fraction = 8; 

Fixed::Fixed(): fixedPoint(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj){
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::Fixed(const float fixed){
    
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->fixedPoint = obj.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const{
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