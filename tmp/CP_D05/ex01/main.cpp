#include "Form.hpp"


int	main()
{
	Bureaucrat robert("Robert", 150);
	std::cout << "** Creating a new Bureaucrat Robert **" << std::endl;
	std::cout << "Using << operator on Robert: " << robert << std::endl;

	Form		form42("42 Commandements", 42, 42);
	std::cout << "** Creating a new Form Form42 **" << std::endl;
	std::cout << "** Using << operator on Form42 ** " << std::endl << form42 << std::endl;
	std::cout << "Robert tries to sign the form" << std::endl;

	try {
		form42.beSigned(robert);
	}
	catch (Form::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat joe("Joe", 42);
	std::cout << std::endl << "** Creating a new Bureaucrat Joe **" << std::endl;
	std::cout << "Using << operator on Joe: " << joe << std::endl;
	std::cout << "Joe tries to sign the form" << std::endl;

	try {
		form42.beSigned(joe);
	}
	catch (Form::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}