#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat john("john", 1);
		std::cout << john.getGrade() << std::endl;
		john.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("Alice", 150);
		std::cout << b2.getGrade() << std::endl;
		b2.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}
