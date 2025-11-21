#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
public:
	Array() noexcept;
	Array(unsigned int n);
	Array(const Array& other);
	Array(Array&& other) noexcept;

	Array& operator=(const Array& other);
	Array& operator=(Array&& other) noexcept;

	~Array();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const noexcept;

private:
	T* _data;
	unsigned int _size;
};

#include "Array.tpp" 

#endif
