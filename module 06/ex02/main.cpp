#include "Base.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "=== Real Type Identification Test ===" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test 1: Random generation and identification" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Round " << (i + 1) << ":" << std::endl;
		Base* obj = generate();
		
		std::cout << "  Generated object at: " << obj << std::endl;
		std::cout << "  Identify by pointer: ";
		identify(obj);
		
		std::cout << "  Identify by reference: ";
		identify(*obj);
		
		delete obj;
		std::cout << std::endl;
	}
	
	std::cout << "Test 2: Specific type creation and identification" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	
	A* directA = new A();
	B* directB = new B();
	C* directC = new C();
	
	std::cout << "Created A object directly:" << std::endl;
	std::cout << "  Address: " << directA << std::endl;
	std::cout << "  By pointer: ";
	identify(directA);
	std::cout << "  By reference: ";
	identify(*directA);
	
	std::cout << "Created B object directly:" << std::endl;
	std::cout << "  Address: " << directB << std::endl;
	std::cout << "  By pointer: ";
	identify(directB);
	std::cout << "  By reference: ";
	identify(*directB);
	
	std::cout << "Created C object directly:" << std::endl;
	std::cout << "  Address: " << directC << std::endl;
	std::cout << "  By pointer: ";
	identify(directC);
	std::cout << "  By reference: ";
	identify(*directC);
	
	std::cout << std::endl;
	
	std::cout << "Test 3: Polymorphic behavior through Base pointers" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	
	Base* polyA = new A();
	Base* polyB = new B();
	Base* polyC = new C();
	
	std::cout << "A through Base pointer:" << std::endl;
	std::cout << "  Base* address: " << polyA << std::endl;
	std::cout << "  By pointer: ";
	identify(polyA);
	std::cout << "  By reference: ";
	identify(*polyA);
	
	std::cout << "B through Base pointer:" << std::endl;
	std::cout << "  Base* address: " << polyB << std::endl;
	std::cout << "  By pointer: ";
	identify(polyB);
	std::cout << "  By reference: ";
	identify(*polyB);
	
	std::cout << "C through Base pointer:" << std::endl;
	std::cout << "  Base* address: " << polyC << std::endl;
	std::cout << "  By pointer: ";
	identify(polyC);
	std::cout << "  By reference: ";
	identify(*polyC);
	
	std::cout << std::endl;
	
	std::cout << "Test 4: NULL pointer handling" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Base* nullPtr = NULL;
	std::cout << "Testing NULL pointer: ";
	identify(nullPtr);
	std::cout << std::endl;
	
	std::cout << "Test 5: Array of Base pointers with mixed types" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	
	Base* objects[5];
	for (int i = 0; i < 5; i++)
	{
		objects[i] = generate();
	}
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Array[" << i << "] - Address: " << objects[i] 
				<< " Type: ";
		identify(objects[i]);
	}
	
	delete directA;
	delete directB;
	delete directC;
	delete polyA;
	delete polyB;
	delete polyC;
	
	for (int i = 0; i < 5; i++)
	{
		delete objects[i];
	}
	
	std::cout << std::endl;
	std::cout << "=== All tests completed successfully! ===" << std::endl;
	
	return 0;
}