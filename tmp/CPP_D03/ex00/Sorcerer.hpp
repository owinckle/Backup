#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer {
	public:
		// Constructors & destructors
		Sorcerer(void);
		Sorcerer(const Sorcerer &src);
		Sorcerer(std::string name, std::string title);
		~Sorcerer(void);

		// Operators
		Sorcerer	&operator=(const Sorcerer &rhs);

		// Set methods
		void		setName(std::string name);
		void		setTitle(std::string title);
		void		polymorph(Victim const &victim) const;

		// Get methods
		std::string	getName(void) const;
		std::string	getTitle(void) const;

	private:
		std::string  _name;
		std::string  _title;
};

std::ostream		&operator<<(std::ostream &out, const Sorcerer &rhs);

#endif