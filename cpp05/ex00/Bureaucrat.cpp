#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){

}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& obj)
{
	if (this != &obj)
	{
		this->grade = obj.getGrade();
	}

	return *this;
}

Bureaucrat::~Bureaucrat(){

}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade Too Low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
