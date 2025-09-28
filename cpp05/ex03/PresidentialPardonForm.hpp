#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
        void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f);