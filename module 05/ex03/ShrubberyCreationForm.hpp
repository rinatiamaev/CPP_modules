#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;

public:
	ShrubberyCreationForm();                                       // Default constructor
	ShrubberyCreationForm(const std::string& target);              // Parametric constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other);     // Copy constructor
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // Copy assignment operator
	virtual ~ShrubberyCreationForm();                              // Destructor

	// Getter
	const std::string& getTarget() const;

	// Override the pure virtual function
	virtual void executeAction() const override;

	// Exception class
	class FileCreationException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
