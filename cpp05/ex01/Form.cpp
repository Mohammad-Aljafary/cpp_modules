#include "Form.hpp"

Form::Form() : name(""), grade(150), gradeEx(150), sign(0) {
}



Form::Form(std::string name, int grade, int gradeEx): name(name), grade(grade), gradeEx(gradeEx), sign(0){
	if (grade < 1 || gradeEx < 1)
		throw GradeTooHighException();
	else if (grade > 150 || gradeEx > 150)
		throw GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form& obj): name(obj.getName()), grade(obj.getGrade()), gradeEx(obj.getGradeEx()), sign(obj.getSign()) {
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		this->sign = obj.sign;
	}
	return *this;
}

std::string Form::getName() const {
	return this->name;
}

int Form::getGrade() const {
	return this->grade;
}

int Form::getGradeEx() const {
	return this->gradeEx;
}

bool Form::getSign() const {
	return this->sign;
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

void Form::beSigned(Bureaucrat& b){

	if (b.getGrade() > this->grade)
		throw GradeTooLowException();
	this->sign = 1;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form Name: " << f.getName() << ", Sign Grade: " << f.getGrade() << ", Execute Grade: " << f.getGradeEx();
	return os;
}
