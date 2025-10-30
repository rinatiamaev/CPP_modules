#include "Bureaucrat.hpp"
#include <iostream>

void testBasicFunctionality() {
	std::cout << "\n=== Testing Basic Functionality ===" << std::endl;
	
	try {
		Bureaucrat bobafet("Bobafet", 50);
		std::cout << bobafet << std::endl;
		
		std::cout << "Name: " << bobafet.getName() << std::endl;
		std::cout << "Grade: " << bobafet.getGrade() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeIncrement() {
	std::cout << "\n=== Testing Grade Increment ===" << std::endl;
	
	try {
		Bureaucrat skywalker("Skywalker", 5);
		std::cout << "Before increment: " << skywalker << std::endl;
		
		skywalker.incrementGrade();
		std::cout << "After increment: " << skywalker << std::endl;
		
		skywalker.incrementGrade();
		std::cout << "After second increment: " << skywalker << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeDecrement() {
	std::cout << "\n=== Testing Grade Decrement ===" << std::endl;
	
	try {
		Bureaucrat anakin("Anakin", 145);
		std::cout << "Before decrement: " << anakin << std::endl;
		
		anakin.decrementGrade();
		std::cout << "After decrement: " << anakin << std::endl;
		
		anakin.decrementGrade();
		std::cout << "After second decrement: " << anakin << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidGradeConstruction() {
	std::cout << "\n=== Testing Invalid Grade Construction ===" << std::endl;
	
	try {
		Bureaucrat invalidHigh("TooHigh", 0);
		std::cout << invalidHigh << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught for grade 0: " << e.what() << std::endl;
	}
	
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
	
	try {
		Bureaucrat topLevel("TopLevel", 1);
		std::cout << "Before increment at grade 1: " << topLevel << std::endl;
		topLevel.incrementGrade();
		std::cout << "After increment: " << topLevel << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat bottomLevel("BottomLevel", 150);
		std::cout << "Before decrement at grade 150: " << bottomLevel << std::endl;
		bottomLevel.decrementGrade();
		std::cout << "After decrement: " << bottomLevel << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testOrthodoxCanonicalForm() {
	std::cout << "\n=== Testing Orthodox Canonical Form ===" << std::endl;
	
	try {
		Bureaucrat original("Original", 42);
		std::cout << "Original: " << original << std::endl;
		
		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;
		
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
