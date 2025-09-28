#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern& Intern::operator=(Intern& obj)
{
    (void)obj;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i = 0;

    for (i = 0; i < 3; i++)
    {
        if (forms[i] == formName)
            break;
    }
    switch (i)
    {
        case 0:
            return new PresidentialPardonForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new ShrubberyCreationForm(target);
        default:
            break;
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}

std::ostream& operator<<(std::ostream& os, const Intern& f) {
    (void)f;
    os << "Intern class instance" << std::endl;
    return os;
}