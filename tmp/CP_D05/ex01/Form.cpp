#include "Form.hpp"

// Coplien
Form::Form(void) : _name("Blank Form"), _signed(false), _sGrade(150), _eGrade(150) {}

Form::Form(Form const &rhs) : _sGrade(rhs._sGrade), _eGrade(rhs._eGrade) {
	*this = rhs;
}

Form::~Form(void) {}

Form		&Form::operator=(Form const &rhs) {
	this->_signed = rhs._signed;
	return (*this);
}

// Constructors
Form::Form(std::string const name, int sgrade, int egrade) : _name(name), _signed(false), _sGrade(sgrade), _eGrade(egrade) {
	if (sgrade < 1 || egrade < 1)
		throw Form::GradeTooHighException();
	else if (sgrade > 150 || egrade > 150)
		throw Form::GradeTooLowException();
}

// Methods
void				Form::signForm(void) {
	this->_signed = true;
}

void				Form::beSigned(Bureaucrat &rhs) {
	if (rhs.getGrade() > this->_sGrade) {
		std::cout << "[Bureaucrat] " << rhs.getName() << " can't sign " << this->_name << " because ";
		throw Form::GradeTooLowException();
	}
	else {
		if (this->_signed)
			std::cout << "[Bureaucrat] " << rhs.getName() << " can't sign " << this->_name << " because it's already signed" << std::endl;
		else {
			std::cout << "[Bureaucrat] " << rhs.getName() << " signs " << this->_name << std::endl;
			signForm();
		}
	}
}

// Getters
std::string		Form::getName(void) const {
	return (this->_name);
}

bool			Form::getSigned(void) const {
	return (this->_signed);
}

int				Form::getSGrade(void) const {
	return (this->_sGrade);
}

int				Form::getEGrade(void) const {
	return (this->_eGrade);
}

/* Nested Classes : Exceptions */

/* GradeTooHighException */
// Coplien
Form::GradeTooHighException::GradeTooHighException(void) {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &rhs) {
	*this = rhs;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &rhs) {
	(void)rhs;
	return (*this);
}

// Methods
const char*	Form::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high");
}

/* GradeTooLowException */
// Coplien
Form::GradeTooLowException::GradeTooLowException(void) {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &rhs) {
	*this = rhs;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &rhs) {
	(void)rhs;
	return (*this);
}

// Methods
const char*	Form::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low");
}

// Operator Overload
std::ostream	&operator<<(std::ostream &o, Form const &rhs) {
	o << "Form details: " << std::endl
		<< "Name: " << rhs.getName() << std::endl
		<< "Signing grade requirement: " << rhs.getSGrade() << std::endl
		<< "Exution grade requirement: " << rhs.getEGrade() << std::endl;
	if (rhs.getSigned())
		o << "Form has been signed" << std::endl;
	else
		o << "Form isn't signed" << std::endl;
	return (o);
}