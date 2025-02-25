#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        static const int FRACT_BIT = 8;
        int fix_point;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        int getRawBits() const;
        void setRawBits(int const raw);
        Fixed& operator=(const Fixed& other);
};

#endif