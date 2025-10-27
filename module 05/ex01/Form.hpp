#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration
class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

public:
	Form();                                                         // Default constructor
	Form(const std::string& name, int gradeToSign, int gradeToExecute); // Parametric constructor
	Form(const Form& other);                                        // Copy constructor
	Form& operator=(const Form& other);                             // Copy assignment operator
	~Form();                                                        // Destructor

	// Getters
	const std::string&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Member functions
	void				beSigned(const Bureaucrat& bureaucrat);

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	void				_validateGrade(int grade);
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
