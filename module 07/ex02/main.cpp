#include <iostream>
#include "array.hpp"

int main() {
	std::cout << "----- Basic Tests -----\n";
	Array<int> a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << '\n';


	std::cout << "\n----- Copy Tests -----\n";
	Array<int> b(a);
	b[0] = 111;

	std::cout << "a[0] = " << a[0] << " (should NOT be 111)\n";
	std::cout << "b[0] = " << b[0] << '\n';


	std::cout << "\n----- Move Tests -----\n";
	Array<int> c = std::move(b);

	std::cout << "c[0] = " << c[0] << '\n';
	std::cout << "b.size() = " << b.size() << " (should be 0)\n";


	std::cout << "\n----- Out-of-bounds Test -----\n";
	try {
		std::cout << a[10] << '\n';
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n----- String Array Test -----\n";
	Array<std::string> s(3);
	s[0] = "Hello";
	s[1] = "C++11";
	s[2] = "World";

	for (unsigned int i = 0; i < s.size(); i++)
		std::cout << s[i] << '\n';

	return 0;
}
