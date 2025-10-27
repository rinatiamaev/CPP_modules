#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternBasicFunctionality() {
	std::cout << "\n=== Testing Intern Basic Functionality ===" << std::endl;
	
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		std::cout << "Testing shrubbery creation form:" << std::endl;
		AForm* shrubForm = intern.makeForm("shrubbery creation", "garden");
		if (shrubForm) {
			std::cout << *shrubForm << std::endl;
			boss.signForm(*shrubForm);
			boss.executeForm(*shrubForm);
			delete shrubForm;
		}
		
		std::cout << "\nTesting robotomy request form:" << std::endl;
		AForm* robotForm = intern.makeForm("robotomy request", "Bender");
		if (robotForm) {
			std::cout << *robotForm << std::endl;
			boss.signForm(*robotForm);
			boss.executeForm(*robotForm);
			delete robotForm;
		}
		
		std::cout << "\nTesting presidential pardon form:" << std::endl;
		AForm* pardonForm = intern.makeForm("presidential pardon", "Arthur Dent");
		if (pardonForm) {
			std::cout << *pardonForm << std::endl;
			boss.signForm(*pardonForm);
			boss.executeForm(*pardonForm);
			delete pardonForm;
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInternInvalidFormName() {
	std::cout << "\n=== Testing Intern Invalid Form Name ===" << std::endl;
	
	try {
		Intern intern;
		
		std::cout << "Trying to create non-existent form:" << std::endl;
		AForm* invalidForm = intern.makeForm("coffee making", "kitchen");
		
		if (invalidForm) {
			std::cout << *invalidForm << std::endl;
			delete invalidForm;
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testCompleteWorkflow() {
	std::cout << "\n=== Testing Complete Workflow (Example from Subject) ===" << std::endl;
	
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		if (rrf) {
			Bureaucrat highLevel("High Level", 1);
			std::cout << *rrf << std::endl;
			highLevel.signForm(*rrf);
			highLevel.executeForm(*rrf);
			delete rrf;
		}
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "=== INTERN AND FORM MANAGEMENT TESTS ===" << std::endl;
	
	testInternBasicFunctionality();
	testInternInvalidFormName();
	testCompleteWorkflow();
	
	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	
	return 0;
}
