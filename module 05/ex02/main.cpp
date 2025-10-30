#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm() {
	std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
	
	try {
		ShrubberyCreationForm shrubForm("home");
		Bureaucrat gardener("Gardener", 140);
		Bureaucrat supervisor("Supervisor", 100);
		
		std::cout << shrubForm << std::endl;
		std::cout << gardener << std::endl;
		
		gardener.signForm(shrubForm);
		std::cout << "After signing: " << shrubForm << std::endl;
		
		supervisor.executeForm(shrubForm);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testRobotomyRequestForm() {
	std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
	
	try {
		RobotomyRequestForm robotForm("Bender");
		Bureaucrat engineer("Engineer", 50);
		
		std::cout << robotForm << std::endl;
		std::cout << engineer << std::endl;
		
		engineer.signForm(robotForm);
		std::cout << "After signing: " << robotForm << std::endl;
		
		engineer.executeForm(robotForm);
		
		std::cout << "\nTrying multiple executions:" << std::endl;
		engineer.executeForm(robotForm);
		engineer.executeForm(robotForm);
		engineer.executeForm(robotForm);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
	
	try {
		PresidentialPardonForm pardonForm("Ford Prefect");
		Bureaucrat president("President", 1);
		
		std::cout << pardonForm << std::endl;
		std::cout << president << std::endl;
		
		president.signForm(pardonForm);
		std::cout << "After signing: " << pardonForm << std::endl;
		
		president.executeForm(pardonForm);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testExecutionWithoutSigning() {
	std::cout << "\n=== Testing Execution Without Signing ===" << std::endl;
	
	try {
		ShrubberyCreationForm unsignedForm("garden");
		Bureaucrat manager("Manager", 100);
		
		std::cout << "Trying to execute unsigned form:" << std::endl;
		std::cout << unsignedForm << std::endl;
		
		manager.executeForm(unsignedForm);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInsufficientGradeForSigning() {
	std::cout << "\n=== Testing Insufficient Grade for Signing ===" << std::endl;
	
	try {
		PresidentialPardonForm vipForm("Arthur Dent");
		Bureaucrat intern("Intern", 150);
		
		std::cout << "Trying to sign with insufficient grade:" << std::endl;
		std::cout << vipForm << std::endl;
		std::cout << intern << std::endl;
		
		intern.signForm(vipForm);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInsufficientGradeForExecution() {
	std::cout << "\n=== Testing Insufficient Grade for Execution ===" << std::endl;
	
	try {
		PresidentialPardonForm pardonForm("Marvin");
		Bureaucrat signer("Signer", 20);  // Can sign but not execute
		Bureaucrat executor("Executor", 10); // Cannot execute (need grade 5)
		
		std::cout << pardonForm << std::endl;
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		
		// Sign with appropriate bureaucrat
		signer.signForm(pardonForm);
		std::cout << "After signing: " << pardonForm << std::endl;
		
		// Try to execute with insufficient grade
		executor.executeForm(pardonForm);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testAllFormsWithHighRankBureaucrat() {
	std::cout << "\n=== Testing All Forms with High-Rank Bureaucrat ===" << std::endl;
	
	try {
		Bureaucrat supremeBureaucrat("Supreme Bureaucrat", 1);
		
		std::cout << supremeBureaucrat << std::endl;
		
		// Test ShrubberyCreationForm
		ShrubberyCreationForm shrub("office");
		supremeBureaucrat.signForm(shrub);
		supremeBureaucrat.executeForm(shrub);
		
		std::cout << std::endl;
		
		// Test RobotomyRequestForm
		RobotomyRequestForm robot("Zaphod");
		supremeBureaucrat.signForm(robot);
		supremeBureaucrat.executeForm(robot);
		
		std::cout << std::endl;
		
		// Test PresidentialPardonForm
		PresidentialPardonForm pardon("Trillian");
		supremeBureaucrat.signForm(pardon);
		supremeBureaucrat.executeForm(pardon);
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testOrthodoxCanonicalForm() {
	std::cout << "\n=== Testing Orthodox Canonical Form ===" << std::endl;
	
	try {
		ShrubberyCreationForm original("original");
		Bureaucrat signer("Signer", 100);
		
		signer.signForm(original);
		std::cout << "Original: " << original << std::endl;
		
		ShrubberyCreationForm copy(original);
		std::cout << "Copy: " << copy << std::endl;
		
		ShrubberyCreationForm assigned("to_be_assigned");
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidFormGrades() {
	std::cout << "\n=== Testing Invalid Form Grades ===" << std::endl;
	
	// Note: Since we can't directly create AForm (it's abstract),
	// we test with concrete classes that might have invalid grades
	// But our concrete classes have fixed valid grades, so this test
	// is more about demonstrating the concept
	
	try {
		std::cout << "All concrete forms have predefined valid grades:" << std::endl;
		ShrubberyCreationForm shrub("test");
		RobotomyRequestForm robot("test");
		PresidentialPardonForm pardon("test");
		
		std::cout << "ShrubberyCreationForm grades: sign " << shrub.getGradeToSign() 
				<< ", exec " << shrub.getGradeToExecute() << std::endl;
		std::cout << "RobotomyRequestForm grades: sign " << robot.getGradeToSign() 
				<< ", exec " << robot.getGradeToExecute() << std::endl;
		std::cout << "PresidentialPardonForm grades: sign " << pardon.getGradeToSign() 
				<< ", exec " << pardon.getGradeToExecute() << std::endl;
				
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "=== AFORM AND CONCRETE FORMS TESTS ===" << std::endl;
	
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testExecutionWithoutSigning();
	testInsufficientGradeForSigning();
	testInsufficientGradeForExecution();
	testAllFormsWithHighRankBureaucrat();
	testOrthodoxCanonicalForm();
	testInvalidFormGrades();
	
	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	
	return 0;
}
