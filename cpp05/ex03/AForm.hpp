#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	const std::string name;
	const int grade;
	const int gradeEx;
	bool sign;

	public:
	AForm();
	AForm(std::string name, int grade, int gradeEx);
	virtual~AForm();
	AForm& operator=(AForm& obj);
	std::string	getName() const;
	int		getGrade() const;
	int		getGradeEx() const;
	void	beSigned(Bureaucrat& b);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
