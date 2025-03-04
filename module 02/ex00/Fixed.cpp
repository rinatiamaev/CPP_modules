#include "Fixed.hpp"

Fixed::Fixed():fix_point(0){
    std::cout<<"Default constructor called\n";
}

Fixed::Fixed(const Fixed& other){
    std::cout<<"Copy constructor called\n";
    this->fix_point = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout<<"Copy assignment operator called\n";
    if (this != &other)
        this->fix_point = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const{
    std::cout<<"getRawBits member function called\n";
    return (this->fix_point);
}

void Fixed::setRawBits(int const raw){
    this->fix_point = raw;
}

Fixed::~Fixed(){
    std::cout<<"Destructor called\n";
}
