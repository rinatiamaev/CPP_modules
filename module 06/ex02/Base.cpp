#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base::~Base()
{
}

Base* generate(void)
{
	// Seed random number generator (only once)
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	
	int random = std::rand() % 3;
	
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (!p)
	{
		std::cout << "Error: NULL pointer" << std::endl;
		return;
	}
	
	// Try dynamic_cast to each type
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	// Since we can't use pointers inside this function, 
	// we use try-catch with dynamic_cast on references
	// dynamic_cast with references throws std::bad_cast on failure
	
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a; // Suppress unused variable warning
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		// Not type A, continue
	}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b; // Suppress unused variable warning
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		// Not type B, continue
	}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c; // Suppress unused variable warning
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		// Not type C
		std::cout << "Unknown type" << std::endl;
	}
}