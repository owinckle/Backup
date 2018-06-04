#include "Bureaucrat.hpp"

int	main()
{
	int i = 0;
	int x = 0;
	Bureaucrat robert("Robert", 1);
	std::cout << "** Creating a new Bureaucrat Robert **" << std::endl;
	std::cout << "Using << operator on Robert: " << robert << std::endl;
	std::cout << "** Incrementing Robert by 1 **" << std::endl;
	try {
		robert.incrementGrade(1);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "** Decrementing Robert by 150 **" << std::endl;
	try {
		robert.decrementGrade(150);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "** Decrementing Robert by 42 **" << std::endl;
	try {
		robert.decrementGrade(42);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << robert;


	std::cout << "** Creating a new Bureaucrat Joe with a grade value of 152 **" << std::endl;
	try {
		Bureaucrat robert("Joe", 152);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}