#include "AForm.hpp"

AForm::AForm() : name(""), grade(150), gradeEx(150), sign(150) {
}

AForm::AForm(std::string name, int grade, int gradeEx): name(name), grade(grade), gradeEx(gradeEx), sign(0){
	if (grade < 1 || gradeEx < 1)
		throw GradeTooHighException();
	else if (grade > 150 || gradeEx > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj): name(obj.getName()), grade(obj.getGrade()), gradeEx(obj.getGradeEx()), sign(obj.getSign()) {
}

AForm::~AForm(){}

AForm& AForm::operator=(const AForm& obj)
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

bool AForm::getSign() const {
	return this->sign;
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

void AForm::beSigned(Bureaucrat& b){
	if(this->sign)
		throw std::runtime_error("Form is already signed");
	if (b.getGrade() > this->grade)
		throw GradeTooLowException();
	this->sign = 1;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form Name: " << f.getName() << ", Sign Grade: " << f.getGrade() << ", Execute Grade: " << f.getGradeEx();
	return os;
}
