#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
        void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f);