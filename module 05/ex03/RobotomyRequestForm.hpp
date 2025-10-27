#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();                                         // Default constructor
	RobotomyRequestForm(const std::string& target);                // Parametric constructor
	RobotomyRequestForm(const RobotomyRequestForm& other);         // Copy constructor
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other); // Copy assignment operator
	virtual ~RobotomyRequestForm();                                // Destructor

	// Getter
	const std::string& getTarget() const;

	// Override the pure virtual function
	virtual void executeAction() const override;
};

#endif
