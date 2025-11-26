#include <iostream>
#include <vector>
#include <ctime>
#include "Span.hpp"

int main()
{
	try {
		// small test
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << '\n';
		std::cout << "longestSpan : " << sp.longestSpan() << '\n';

		// test addRange and exception when exceeding
		Span sp2(10000);
		std::vector<int> batch;
		batch.reserve(10000);
		for (int i = 0; i < 10000; ++i)
			batch.push_back(i * 2); // predictable values
		sp2.addRange(batch.begin(), batch.end());
		std::cout << "sp2 size: " << sp2.size() << ", shortest: " << sp2.shortestSpan()
				<< ", longest: " << sp2.longestSpan() << '\n';

		// random large test
		Span sp3(10000);
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		for (int i = 0; i < 10000; ++i)
			sp3.addNumber(std::rand());
		std::cout << "sp3 populated with 10000 random numbers -> shortest: "
				<< sp3.shortestSpan() << ", longest: " << sp3.longestSpan() << '\n';

		// attempt overflow
		try {
			sp.addNumber(42); // should throw (sp has capacity 5)
		} catch (const std::exception& e) {
			std::cout << "expected exception: " << e.what() << '\n';
		}

	} catch (const std::exception& e) {
		std::cerr << "Unhandled exception: " << e.what() << '\n';
		return 1;
	}
	return 0;
}