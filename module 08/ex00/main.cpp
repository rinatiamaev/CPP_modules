#include <array>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::array<int, 8> c{6, 2, 3, 5, 1000, -42, 0, 42};
	int toFind = 42;

	std::size_t i = easyfind(c, toFind);

	std::cout << "ToFind: " << toFind << '\n';
	if (i == EASYFIND_NPOS)
		std::cout << "easyFind: not found\n";
	else
		std::cout << "easyFind returns i: " << i << "\nContainer[i]: " << c[i] << '\n';

	toFind = 43;
	i = easyfind(c, toFind);

	std::cout << "\nToFind: " << toFind << '\n';
	if (i == EASYFIND_NPOS)
		std::cout << "easyFind: not found\n";
	else
		std::cout << "easyFind returns i: " << i << "\nContainer[i]: " << c[i] << '\n';

	return 0;
}