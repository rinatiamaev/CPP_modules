#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <exception>

class Intern {
private:
	// Array of form names and corresponding creation functions
	struct FormCreator {
		std::string name;
		AForm* (*createFunc)(const std::string& target);
	};
	
	static const FormCreator _formCreators[];
	static const size_t _numForms;
	
	// Static creation functions for each form type
	static AForm* createShrubberyCreationForm(const std::string& target);
	static AForm* createRobotomyRequestForm(const std::string& target);
	static AForm* createPresidentialPardonForm(const std::string& target);

public:
	Intern();                                              // Default constructor
	Intern(const Intern& other);                           // Copy constructor
	Intern& operator=(const Intern& other);                // Copy assignment operator
	~Intern();                                             // Destructor

	// Main funct.
	AForm* makeForm(const std::string& formName, const std::string& target);

	// Exception class
	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
