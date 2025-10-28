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
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string&	getName() const;
	int					getGrade() const;

	
	void				incrementGrade();
	void				decrementGrade();

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
