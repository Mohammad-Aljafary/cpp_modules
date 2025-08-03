#include "Fixed.hpp"

const int Fixed::fraction = 8;


/*****************constructors********************/

Fixed::Fixed(): fixedPoint(0){
}

Fixed::Fixed(const Fixed& obj){
    *this = obj;
}

Fixed::Fixed(const float fixed){
    fixedPoint = static_cast<int>(roundf(fixed * (1 << fraction)));
}

Fixed::Fixed(const int fixed){
    fixedPoint = fixed * (1 << fraction);
}


/************assignment operator**************/

Fixed& Fixed::operator=(const Fixed& obj) {
    if (this != &obj) {
        this->fixedPoint = obj.getRawBits();
    }
    return *this;
}

/**********casting functions***************/

float Fixed::toFloat( void ) const{
    return static_cast<float>(fixedPoint) / (1 << fraction);
}

int Fixed::toInt( void ) const{
    return fixedPoint / (1 << fraction);
}


/**********get/set functions************/

int Fixed::getRawBits( void ) const{
    return fixedPoint;
}

void Fixed::setRawBits( int const raw ){
    fixedPoint = raw;
}

/*********destructor***********/

Fixed::~Fixed(){
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

/*****************Arithmetic operations****************/

Fixed Fixed::operator+(const Fixed& other) const{
    return Fixed(this->fixedPoint + other.fixedPoint);
}

Fixed Fixed::operator-(const Fixed& other) const{
    return Fixed(this->fixedPoint - other.fixedPoint);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed result;
    long long product = static_cast<long long>(this->fixedPoint) * other.fixedPoint;
    result.fixedPoint = static_cast<int>(product >> fraction);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const{
    if (other.fixedPoint == 0)
        throw std::runtime_error("Division by zero");

    Fixed result;
    long long dividend = (static_cast<long long>(this->fixedPoint) << fraction);
    result.fixedPoint = static_cast<int>(dividend / other.fixedPoint);
    return result;

}

/****************comparison operations***********************/


bool Fixed::operator==(const Fixed& other) const{
    return this->fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const{
    return this->fixedPoint != other.fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const{
    return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const{
    return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator>(const Fixed& other) const{
    return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const{
    return this->fixedPoint >= other.fixedPoint;
}


/*******post/pre increments/decrements*********/

/*pre*/
Fixed& Fixed::operator++(){
   ++(fixedPoint);
   return *this;
}

/*post*/
Fixed Fixed::operator++(int){
    Fixed temp = *this;
    ++(*this);
    return temp;
}
/*pre*/
Fixed& Fixed::operator--(){
    --fixedPoint;
    return *this;
}

/*post*/
Fixed Fixed::operator--(int){
    Fixed temp = *this;
    --(*this);
    return temp;
}

/********min/max functions**********/

Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
    if (num1.fixedPoint > num2.fixedPoint)
        return num2;
    else
        return num1;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
    if (num1.fixedPoint > num2.fixedPoint)
        return num2;
    else
        return num1;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
    if (num1.fixedPoint > num2.fixedPoint)
        return num1;
    else
        return num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
    if (num1.fixedPoint > num2.fixedPoint)
        return num1;
    else
        return num2;
}

