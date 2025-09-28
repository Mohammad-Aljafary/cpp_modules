#pragma once 


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& obj);
        void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);