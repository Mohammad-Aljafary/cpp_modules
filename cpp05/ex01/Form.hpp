#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
	const std::string name;
	bool sign;
	const int grade;
	const int gradeEx;

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
    const char* what() const throw() {
        return "Grade too low to sign the form";
    }
};


};


#endif
