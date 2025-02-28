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

bool Fixed::operator>(const Fixed& other) const {
    return fix_point > other.fix_point;
}

bool Fixed::operator<(const Fixed& other) const {
    return fix_point < other.fix_point;
}

bool Fixed::operator>=(const Fixed& other) const {
    return fix_point >= other.fix_point;
}

bool Fixed::operator<=(const Fixed& other) const {
    return fix_point <= other.fix_point;
}

bool Fixed::operator==(const Fixed& other) const {
    return fix_point == other.fix_point;
}

bool Fixed::operator!=(const Fixed& other) const {
    return fix_point != other.fix_point;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.fix_point == 0) {
        std::cerr << "Error: Division by zero\n";
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++fix_point;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++fix_point;
    return temp;
}

Fixed& Fixed::operator--() {
    --fix_point;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --fix_point;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}