#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
	
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

public:
	Bureaucrat();                                          // Default constructor
	Bureaucrat(const std::string& name, int grade);        // Parametric constructor
	Bureaucrat(const Bureaucrat& other);                   // Copy constructor
	Bureaucrat& operator=(const Bureaucrat& other);        // Copy assignment operator
	~Bureaucrat();                                         // Destructor

	// Getters
	const std::string&	getName() const;
	int					getGrade() const;

	// Member functions
	void				incrementGrade();
	void				decrementGrade();

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
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
