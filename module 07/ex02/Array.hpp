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
	Array() noexcept;
	explicit Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const noexcept;
};

#include "Array.tpp"

#endif
