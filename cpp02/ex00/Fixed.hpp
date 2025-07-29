#pragma once

#include <iostream>

class Fixed {
    private:
    int fixedPoint;
    static const int fraction;

    public:
    Fixed();
    Fixed(const Fixed& obj);
    Fixed& operator=(const Fixed& obj);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );

};