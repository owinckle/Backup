#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
public:
	// Constructors & Destructors
	Victim(void);
	Victim(const Victim &src);
	Victim(std::string name);
	~Victim(void); 

	// Operators
	Victim		&operator= (const Victim &rhs); 

	// Set methods
	void		  setName(std::string name);

	// Get methods
	std::string   getName(void) const;
	virtual void  getPolymorphed(void) const;

private:
	std::string		_name;
};

std::ostream	  &operator<< (std::ostream &out, const Victim &rhs);

#endif