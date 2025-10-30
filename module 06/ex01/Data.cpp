#include "Data.hpp"
#include <iostream>

Data::Data() : id(0), name(""), value(0.0f), active(false)
{
}

Data::Data(int id, const std::string& name, float value, bool active)
	: id(id), name(name), value(value), active(active)
{
}

bool Data::operator==(const Data& other) const
{
	return (id == other.id && 
			name == other.name && 
			value == other.value && 
			active == other.active);
}

void Data::display() const
{
	std::cout << "Data { id: " << id 
			<< ", name: \"" << name 
			<< "\", value: " << value 
			<< ", active: " << (active ? "true" : "false") 
			<< " }" << std::endl;
}
