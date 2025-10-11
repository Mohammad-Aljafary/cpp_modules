#pragma once

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& obj);
    Intern& operator=(const Intern& obj);
    AForm* makeForm(std::string formName, std::string target);
};

std::ostream& operator<<(std::ostream& os, const Intern& f);