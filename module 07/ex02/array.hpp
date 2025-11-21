#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
    T*            _data;
    unsigned int  _size;

public:
    // Default constructor
    Array() noexcept;

    // Constructor with size n
    explicit Array(unsigned int n);

    // Copy constructor
    Array(const Array& other);

    // Move constructor (C++11)
    Array(Array&& other) noexcept;

    // Copy assignment operator
    Array& operator=(const Array& other);

    // Move assignment operator (C++11)
    Array& operator=(Array&& other) noexcept;

    // Destructor
    ~Array();

    // Element access with bounds checking
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // size()
    unsigned int size() const noexcept;
};

// template implementation
#include "array.tpp"

#endif
