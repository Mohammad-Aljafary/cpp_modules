#include "Form.hpp"

Form::Form() : name(""), grade(0), gradeEx(0), sign(0) {
}

Form::Form(std::string name, int grade, int gradeEx): name(name), grade(grade), gradeEx(gradeEx), sign(0){
}

Form::~Form(){}

Form& Form::operator=(Form& obj)
{
	if (this != &obj)
	{
		this->sign = obj.sign;
	}
	return *this;
}

std::string Form::getName(){
	return this->name;
}

int Form::getGrade(){
	return this->grade;
}

int Form::getGradeEx(){
	return this->gradeEx;
}

const char* Form::GradeTooLowException::what() const throw(){
	return 
}

void Form::beSigned(Bureaucrat& b){

	if (b.getGrade() > this->grade)
		throw GradeTooLowException();

}
