#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration
class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

public:
	AForm();                                                        // Default constructor
	AForm(const std::string& name, int gradeToSign, int gradeToExecute); // Parametric constructor
	AForm(const AForm& other);                                      // Copy constructor
	AForm& operator=(const AForm& other);                           // Copy assignment operator
	virtual ~AForm();                                               // Virtual destructor

	// Getters
	const std::string&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Member functions
	void				beSigned(const Bureaucrat& bureaucrat);
	void				execute(const Bureaucrat& executor) const;

	// Pure virtual function - makes this class abstract
	virtual void		executeAction() const = 0;

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	void				_validateGrade(int grade);
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
