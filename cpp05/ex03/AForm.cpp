#include "AForm.hpp"

AForm::AForm() : name(""), grade(0), gradeEx(0), sign(0) {
}

AForm::AForm(std::string name, int grade, int gradeEx): name(name), grade(grade), gradeEx(gradeEx), sign(0){
}

AForm::~AForm(){}

AForm& AForm::operator=(AForm& obj)
{
	if (this != &obj)
	{
		this->sign = obj.sign;
	}
	return *this;
}

std::string AForm::getName() const{
	return this->name;
}

int AForm::getGrade() const {
	return this->grade;
}

int AForm::getGradeEx() const {
	return this->gradeEx;
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

void AForm::beSigned(Bureaucrat& b){

	if (b.getGrade() > this->grade)
		throw GradeTooLowException();
	this->sign = 1;
}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form Name: " << f.getName() << ", Sign Grade: " << f.getGrade() << ", Execute Grade: " << f.getGradeEx();
	return os;
}