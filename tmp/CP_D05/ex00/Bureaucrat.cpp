#include "Bureaucrat.hpp"

// Coplien
Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) {
	*this = rhs;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &rhs) {
	this->_grade = rhs._grade;
	return (*this);
}

// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// Methods
void			Bureaucrat::incrementGrade(int val) {
	if (this->_grade - val < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= val;
}

void			Bureaucrat::decrementGrade(int val) {
	if (this->_grade + val > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += val;
}

// Getters
std::string		Bureaucrat::getName(void) const{
	return (this->_name);
}

int				Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

/* Nested Classes : Exceptions */

/* GradeTooHighException */
// Coplien
Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &rhs) {
	*this = rhs;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs) {
	(void)rhs;
	return (*this);
}

// Methods
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high (< 1)");
}

/* GradeTooLowException */
// Coplien
Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &rhs) {
	*this = rhs;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs) {
	(void)rhs;
	return (*this);
}

// Methods
const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low (> 150)");
}

// Operator Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs) {
	o << "[" << rhs.getName() << "] has a grade of " << rhs.getGrade() << std::endl;
	return (o);
}