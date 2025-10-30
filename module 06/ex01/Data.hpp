#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	int id;
	std::string name;
	float value;
	bool active;
	
	Data();
	Data(int id, const std::string& name, float value, bool active);
	
	bool operator==(const Data& other) const;
	void display() const;
};

#endif
