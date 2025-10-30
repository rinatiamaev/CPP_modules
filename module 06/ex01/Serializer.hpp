#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	// Private constructor to prevent instantiation
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();

public:
	// Static methods for serialization/deserialization
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
