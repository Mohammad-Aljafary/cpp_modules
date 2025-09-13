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
    Fixed (const int fixed);
    Fixed(const Fixed& obj);
    Fixed& operator=(const Fixed& obj);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed& min(Fixed& num1, Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
    static Fixed& max(Fixed& num1, Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);