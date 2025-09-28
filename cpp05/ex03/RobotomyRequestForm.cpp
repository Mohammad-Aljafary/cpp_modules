#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
        this->target = obj.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeEx())
        throw AForm::GradeTooLowException();
    srand(time(NULL));
    if (rand() % 2)
        std::cout << "Bzzzzzz... " << this->target << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << "Bzzzzzz... " << this->target << " has failed to be robotomized." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f) {
    os << "Form Name: " << f.getName() << ", Sign Grade: " << f.getGrade() << ", Execute Grade: " << f.getGradeEx();
    return os;
}