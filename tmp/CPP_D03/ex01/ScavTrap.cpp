#include "ScavTrap.hpp"

/*
** Constructors and destructors
*/

ScavTrap::ScavTrap(void) {}

ScavTrap::~ScavTrap(void) {
    std::cout << this->_name << " has been defeated..." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << name << ": Welcome traveler!" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeAttackDamagePoints = 20;
    this->_rangedAttackDamagePoints = 15;
    this->_armorDamageReductionPoints = 3;
    return ;
}

/*
** Operators
*/

ScavTrap    &ScavTrap::operator= (ScavTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_level = rhs._level;
	this->_meleeAttackDamagePoints = rhs._meleeAttackDamagePoints;
	this->_rangedAttackDamagePoints = rhs._rangedAttackDamagePoints;
	this->_armorDamageReductionPoints = rhs._armorDamageReductionPoints;
  return (*this);
}

/*
** Attacks
*/

void        ScavTrap::meleeAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with melee, causing " << this->_meleeAttackDamagePoints \
              << " points of damage!" << std::endl;
}

void        ScavTrap::rangedAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " at range, causing " << this->_rangedAttackDamagePoints \
              << " points of damage!" << std::endl;
}

/*
** Damage calculations
*/

void        ScavTrap::takeDamage(unsigned int amount) {
    unsigned int    damage;

    if (amount < this->_armorDamageReductionPoints)
        amount = this->_armorDamageReductionPoints;
    damage = amount - this->_armorDamageReductionPoints;
    if (damage >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << this->_name << " is already dead, stop it you savage..." << std::endl;
    }
    else {
        this->_hitPoints -= damage;
        std::cout << std::endl << this->_name << " is still standing!" << std::endl;
        std::cout << "Armor reduction: " << this->_armorDamageReductionPoints\
                  << std::endl;
        std::cout << "Damage taken: " << damage << std::endl;
        std::cout << "Health points left: " << this->_hitPoints << " / " \
                  << this->_maxHitPoints << std::endl;
    }
}

void        ScavTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints < amount) {
        std::cout << this->_name << ": Not enough energy... :(" << std::endl;
    }
    else {
        if (this->_hitPoints + amount > this->_maxHitPoints)
            this->_hitPoints = this->_maxHitPoints;
        else
            this->_hitPoints = amount + this->_hitPoints;
        this->_energyPoints -= amount;
        std::cout << this->_name << " is healing himself for " << amount << " health points" << std::endl;
        std::cout << "Health points: " << this->_hitPoints << std::endl;
    }
    std::cout << "Energy points left: " << this->_energyPoints << std::endl;
}

void        ScavTrap::challengeNewcomer(std::string const &target) {
  int         random;
    std::string challenge[] =
    {
        "take a laxative",
        "prepare and eat ramen using something other than water",
        "rub peanut butter all over your face, for absolute no reason",
        "tie your shoes the way you're not used to tying them",
        "cook yourself a lovely dinner and somehow incorporate pickles in it"
    };

    srand(time(NULL));
    random = rand() % 5;
  this->_challenge = challenge[random];
    std::cout << this->_name << ": I challenge you to " << this->_challenge \
              << " right now! Good luck, " << target \
              <<  "... Muahahaha :D" << std::endl;
}

/*
** Get methods
*/

std::string     ScavTrap::getName(void) {
    return (this->_name);
}

unsigned int      ScavTrap::getMeleeAttackDamage(void)  {
    return (this->_meleeAttackDamagePoints);
}

unsigned int      ScavTrap::getRangedAttackDamage(void) {
    return (this->_rangedAttackDamagePoints);
}

unsigned int      ScavTrap::getArmorDamageReduction(void)  {
    return (this->_armorDamageReductionPoints);
}

unsigned int      ScavTrap::getHealthPoints(void) {
  return (this->_hitPoints);
}

std::string       ScavTrap::getChallenge(void) {
    return (this->_challenge);
}
