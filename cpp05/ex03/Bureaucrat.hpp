#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat& operator=(Bureaucrat& obj);
	~Bureaucrat();
	std::string	getName() const;
	int		getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm& f);
	void	executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
