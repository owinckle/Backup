#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {
public:
	// Constructors & Destructors
	Peon(void);
	Peon(const Peon &src);
	Peon(std::string name);
	~Peon(void);

	// Operators
	Peon			&operator= (const Peon &rhs);
	// Get methods
	virtual void	getPolymorphed(void) const;

private:
		std::string _name;
};

#endif