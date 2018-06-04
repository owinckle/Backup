#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
public:
	// Coplien
	Form(void);
	Form(Form const &rhs);
	virtual ~Form(void);
	Form	&operator=(Form const &rhs);

	// Constructors
	Form(std::string const name, int sgrade, int egrade);

	// Methods
	void			signForm(void);
	void			beSigned(Bureaucrat &rhs);

	// Getters
	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getSGrade(void) const;
	int				getEGrade(void) const;

	// Nested Classes : Exceptions
	class GradeTooHighException : public std::exception {
	public:
		// Coplien
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &rhs);
		virtual ~GradeTooHighException(void) throw();
		GradeTooHighException	&operator=(GradeTooHighException const &rhs);

		// Methods
		virtual const char*		what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		// Coplien
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &rhs);
		virtual ~GradeTooLowException(void) throw();
		GradeTooLowException	&operator=(GradeTooLowException const &rhs);

		// Methods
		virtual const char*		what() const throw();
	};

private:
	std::string const	_name;
	bool				_signed;
	int const			_sGrade;
	int const			_eGrade;
};

// Operator Overload
std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif