#include "Fixed.hpp"

Fixed::Fixed():fix_point(0){
    std::cout<<"Default constructor called\n";
}

Fixed::Fixed(const int int_value) {
    std::cout << "Int constructor called" << std::endl;
    fix_point = int_value << FRACT_BIT;
}

Fixed::Fixed(const float float_value) {
    std::cout << "Float constructor called" << std::endl;
    fix_point = roundf(float_value * (1 << FRACT_BIT));
}

Fixed::Fixed(const Fixed& other){
    std::cout<<"Copy constructor called\n";
    this->fix_point = other.fix_point;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout<<"Copy assignment operator called\n";
    if (this != &other)
        this->fix_point = other.fix_point;
    return (*this);
}

Fixed::~Fixed(){
    std::cout<<"Destructor called\n";
}

int Fixed::getRawBits() const{
    std::cout<<"getRawBits member function called\n";
    return (this->fix_point);
}

void Fixed::setRawBits(int const raw){
    this->fix_point = raw;
}

float Fixed::toFloat(void) const {
    return (float)fix_point / (1 << FRACT_BIT);
}

int Fixed::toInt(void) const {
    return fix_point >> FRACT_BIT;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}