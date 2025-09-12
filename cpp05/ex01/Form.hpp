#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
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
	~Form();
	Form& operator=(Form& obj);
	std::string	getName();
	int		getGrade();
	int		getGradeEx();
	void	beSigned(Bureaucrat& b);

	class GradeTooLowException : public std::exception {
	public:
    const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
	const char* what() const throw();
	};
};

#endif