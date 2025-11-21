#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T &x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
    x++;
}

int main() {
	// ----- INT ARRAY -----
	int intArray[5] = {1, 2, 3, 4, 5};

	std::cout << "Print integers:" << std::endl;
	iter(intArray, 5, printElement<int>);

	std::cout << "Increment integers:" << std::endl;
	iter(intArray, 5, increment<int>);
	iter(intArray, 5, printElement<int>);


	// ----- STRING ARRAY -----
	std::string strArray[3] = {"Hello", "World", "!"};

	std::cout << "\nPrint strings:" << std::endl;
	iter(strArray, 3, printElement<std::string>);


	// ----- CHAR ARRAY -----
	char charArray[4] = {'A', 'B', 'C', 'D'};

	std::cout << "\nPrint chars:" << std::endl;
	iter(charArray, 4, printElement<char>);

	return 0;
}
