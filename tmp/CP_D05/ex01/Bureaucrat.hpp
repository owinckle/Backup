#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
public:
	// Coplien
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &rhs);
	virtual 	~Bureaucrat(void);
	Bureaucrat	&operator=(Bureaucrat const &rhs);

	// Constructors
	Bureaucrat(std::string name, int grade);

	// Methods
	void		decrementGrade(int val);
	void		incrementGrade(int val);


	// Getters
	std::string	getName(void) const;
	int			getGrade(void) const;

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
	int					_grade;

};

// Operator Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif