#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	const std::string name;
	const int grade;
	const int gradeEx;
	bool sign;

	public:
	Form();
	Form(std::string name, int grade, int gradeEx);
	Form(const Form& obj);
	~Form();
	Form& operator=(const Form& obj);
	std::string	getName() const;
	int		getGrade() const;
	bool		getSign() const;
	int		getGradeEx() const;
	void	beSigned(Bureaucrat& b);

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
