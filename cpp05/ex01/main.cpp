#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("A", 74);
	Bureaucrat b("B", 150);
	Form f("Form1", 75, 50);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << f.getName() << ", form grade " << f.getGrade() << ", execution grade " << f.getGradeEx() << std::endl;
	try {
		b.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		a.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	b.signForm(f);
	a.signForm(f);

	return 0;

}
