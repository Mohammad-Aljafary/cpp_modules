#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
    int fixedPoint;
    static const int fraction;

    public:
    Fixed();
    Fixed(const float fixed);
    Fixed(const Fixed& obj);
    Fixed& operator=(const Fixed& obj);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};