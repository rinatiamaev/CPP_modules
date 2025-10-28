#include "Intern.hpp"
#include <cctype>

const Intern::FormCreator Intern::_formCreators[] = {
	{"shrubbery creation", &Intern::createShrubberyCreationForm},
	{"robotomy request", &Intern::createRobotomyRequestForm},
	{"presidential pardon", &Intern::createPresidentialPardonForm}
};

const size_t Intern::_numForms = sizeof(_formCreators) / sizeof(_formCreators[0]);

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string lowerFormName = formName;
	for (char& c : lowerFormName) {
		c = std::tolower(c);
	}
	
	for (size_t i = 0; i < _numForms; ++i) {
		if (_formCreators[i].name == lowerFormName) {
			std::cout << "Intern creates " << formName << std::endl;
			return _formCreators[i].createFunc(target);
		}
	}
	
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found! Available forms: shrubbery creation, robotomy request, presidential pardon";
}
