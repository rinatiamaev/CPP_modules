#include "Bureaucrat.hpp"
#include <iostream>

void testBasicFunctionality() {
	std::cout << "\n=== Testing Basic Functionality ===" << std::endl;
	
	try {
		Bureaucrat john("Bobafet", 50);
		std::cout << john << std::endl;
		
		std::cout << "Name: " << john.getName() << std::endl;
		std::cout << "Grade: " << john.getGrade() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeIncrement() {
	std::cout << "\n=== Testing Grade Increment ===" << std::endl;
	
	try {
		Bureaucrat alice("Skywalker", 5);
		std::cout << "Before increment: " << alice << std::endl;
		
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		
		alice.incrementGrade();
		std::cout << "After second increment: " << alice << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeDecrement() {
	std::cout << "\n=== Testing Grade Decrement ===" << std::endl;
	
	try {
		Bureaucrat bob("Anakin", 145);
		std::cout << "Before decrement: " << bob << std::endl;
		
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
		
		bob.decrementGrade();
		std::cout << "After second decrement: " << bob << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidGradeConstruction() {
	std::cout << "\n=== Testing Invalid Grade Construction ===" << std::endl;
	
	// Test grade too high
	try {
		Bureaucrat invalidHigh("TooHigh", 0);
		std::cout << invalidHigh << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught for grade 0: " << e.what() << std::endl;
	}
	
	// Test grade too low
	try {
		Bureaucrat invalidLow("TooLow", 151);
		std::cout << invalidLow << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught for grade 151: " << e.what() << std::endl;
	}
}

void testGradeLimits() {
	std::cout << "\n=== Testing Grade Limits ===" << std::endl;
	
	// Test incrementing at highest grade
	try {
		Bureaucrat topLevel("TopLevel", 1);
		std::cout << "Before increment at grade 1: " << topLevel << std::endl;
		topLevel.incrementGrade(); // This should throw
		std::cout << "After increment: " << topLevel << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// Test decrementing at lowest grade
	try {
		Bureaucrat bottomLevel("BottomLevel", 150);
		std::cout << "Before decrement at grade 150: " << bottomLevel << std::endl;
		bottomLevel.decrementGrade(); // This should throw
		std::cout << "After decrement: " << bottomLevel << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testOrthodoxCanonicalForm() {
	std::cout << "\n=== Testing Orthodox Canonical Form ===" << std::endl;
	
	// Test copy constructor
	try {
		Bureaucrat original("Original", 42);
		std::cout << "Original: " << original << std::endl;
		
		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;
		
		// Test assignment operator
		Bureaucrat assigned("ToBeAssigned", 100);
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "=== BUREAUCRAT TESTS ===" << std::endl;
	
	testBasicFunctionality();
	testGradeIncrement();
	testGradeDecrement();
	testInvalidGradeConstruction();
	testGradeLimits();
	testOrthodoxCanonicalForm();
	
	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	
	return 0;
}
