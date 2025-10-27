#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testBasicFormFunctionality() {
	std::cout << "\n=== Testing Basic Form Functionality ===" << std::endl;
	
	try {
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
		
		std::cout << "Name: " << taxForm.getName() << std::endl;
		std::cout << "Is signed: " << (taxForm.isSigned() ? "yes" : "no") << std::endl;
		std::cout << "Grade to sign: " << taxForm.getGradeToSign() << std::endl;
		std::cout << "Grade to execute: " << taxForm.getGradeToExecute() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidFormGrades() {
	std::cout << "\n=== Testing Invalid Form Grades ===" << std::endl;
	
	// Test grade too high for signing
	try {
		Form invalidForm1("Invalid Form 1", 0, 50);
		std::cout << invalidForm1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught for grade to sign 0: " << e.what() << std::endl;
	}
	
	// Test grade too low for execution
	try {
		Form invalidForm2("Invalid Form 2", 50, 151);
		std::cout << invalidForm2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught for grade to execute 151: " << e.what() << std::endl;
	}
}

void testFormSigning() {
	std::cout << "\n=== Testing Form Signing ===" << std::endl;
	
	try {
		Form applicationForm("Job Application", 30, 20);
		Bureaucrat manager("Manager", 25);
		
		std::cout << "Before signing:" << std::endl;
		std::cout << applicationForm << std::endl;
		std::cout << manager << std::endl;
		
		manager.signForm(applicationForm);
		
		std::cout << "After signing:" << std::endl;
		std::cout << applicationForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testFormSigningFailure() {
	std::cout << "\n=== Testing Form Signing Failure ===" << std::endl;
	
	try {
		Form vipForm("VIP Access Form", 10, 5);
		Bureaucrat intern("Intern", 100);
		
		std::cout << "Before signing attempt:" << std::endl;
		std::cout << vipForm << std::endl;
		std::cout << intern << std::endl;
		
		intern.signForm(vipForm);
		
		std::cout << "After signing attempt:" << std::endl;
		std::cout << vipForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testMultipleSigning() {
	std::cout << "\n=== Testing Multiple Signing ===" << std::endl;
	
	try {
		Form contractForm("Contract Form", 40, 30);
		Bureaucrat supervisor("Supervisor", 35);
		Bureaucrat director("Director", 10);
		
		std::cout << "Initial state:" << std::endl;
		std::cout << contractForm << std::endl;
		
		// First signing
		supervisor.signForm(contractForm);
		std::cout << "After first signing:" << std::endl;
		std::cout << contractForm << std::endl;
		
		// Second signing (should still work)
		director.signForm(contractForm);
		std::cout << "After second signing:" << std::endl;
		std::cout << contractForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testBoundaryGrades() {
	std::cout << "\n=== Testing Boundary Grades ===" << std::endl;
	
	try {
		// Form with highest possible grades
		Form highForm("High Security Form", 1, 1);
		Bureaucrat topBureaucrat("Top Bureaucrat", 1);
		
		std::cout << "High security form:" << std::endl;
		std::cout << highForm << std::endl;
		std::cout << topBureaucrat << std::endl;
		
		topBureaucrat.signForm(highForm);
		std::cout << "After signing:" << std::endl;
		std::cout << highForm << std::endl;
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		// Form with lowest possible grades
		Form lowForm("Basic Form", 150, 150);
		Bureaucrat basicBureaucrat("Basic Bureaucrat", 150);
		
		std::cout << "\nBasic form:" << std::endl;
		std::cout << lowForm << std::endl;
		std::cout << basicBureaucrat << std::endl;
		
		basicBureaucrat.signForm(lowForm);
		std::cout << "After signing:" << std::endl;
		std::cout << lowForm << std::endl;
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testOrthodoxCanonicalForm() {
	std::cout << "\n=== Testing Orthodox Canonical Form ===" << std::endl;
	
	try {
		Form original("Original Form", 42, 24);
		Bureaucrat signer("Signer", 30);
		
		// Sign the original
		signer.signForm(original);
		std::cout << "Original: " << original << std::endl;
		
		// Test copy constructor
		Form copy(original);
		std::cout << "Copy: " << copy << std::endl;
		
		// Test assignment operator
		Form assigned("To Be Assigned", 100, 80);
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "=== FORM AND BUREAUCRAT TESTS ===" << std::endl;
	
	testBasicFormFunctionality();
	testInvalidFormGrades();
	testFormSigning();
	testFormSigningFailure();
	testMultipleSigning();
	testBoundaryGrades();
	testOrthodoxCanonicalForm();
	
	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	
	return 0;
}
