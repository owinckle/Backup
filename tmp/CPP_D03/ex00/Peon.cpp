#include "Peon.hpp"

// Constructors & Destructors

Peon::Peon(void) {
	this->_name = "Edward";
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(std::string name) {
	this->_name = name;
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(const Peon &src) {
	*this = src;
	return ;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
	return ;
}

// Operators

Peon	&Peon::operator= (const Peon &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

// Get methods

void	Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony !" \
			<< std::endl;
	return ;
}