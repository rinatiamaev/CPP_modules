#ifndef ARRAY_TPP
#define ARRAY_TPP

// Default constructor
template <typename T>
Array<T>::Array() noexcept : _data(nullptr), _size(0) {}

// Size constructor
template <typename T>
Array<T>::Array(unsigned int n) : _data(nullptr), _size(n) {
	_data = new T[n]();  // value-initialize elements
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _data(nullptr), _size(other._size) {
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

// Move constructor (C++11)
template <typename T>
Array<T>::Array(Array&& other) noexcept
	: _data(other._data), _size(other._size) {
	other._data = nullptr;
	other._size = 0;
}

// Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		T* newData = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i)
			newData[i] = other._data[i];

		delete[] _data;

		_data = newData;
		_size = other._size;
	}
	return *this;
}

// Move assignment operator
template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
	if (this != &other) {
		delete[] _data;

		_data = other._data;
		_size = other._size;

		other._data = nullptr;
		other._size = 0;
	}
	return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

// Element access
template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

// size()
template <typename T>
unsigned int Array<T>::size() const noexcept {
	return _size;
}

#endif
