#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        PresidentialPardonForm form1("Target1");
        RobotomyRequestForm form2("Target2");
        ShrubberyCreationForm form3("Target3");

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;

        bob.signForm(form1);
        bob.executeForm(form1);

        bob.signForm(form2);
        bob.executeForm(form2);

        alice.signForm(form3); // This should fail
        bob.signForm(form3);
        alice.executeForm(form3);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}