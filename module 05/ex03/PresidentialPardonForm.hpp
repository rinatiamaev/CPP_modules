#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	PresidentialPardonForm();                                      // Default constructor
	PresidentialPardonForm(const std::string& target);             // Parametric constructor
	PresidentialPardonForm(const PresidentialPardonForm& other);   // Copy constructor
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // Copy assignment operator
	virtual ~PresidentialPardonForm();                             // Destructor

	// Getter
	const std::string& getTarget() const;

	// Override the pure virtual function
	virtual void executeAction() const override;
};

#endif
