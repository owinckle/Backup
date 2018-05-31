#include "FragTrap.hpp"

/*
** Constructors and destructors
*/

FragTrap::FragTrap(void) {}

FragTrap::~FragTrap(void) {
    std::cout << this->_name << " has been destroyed..." << std::endl;
}

FragTrap::FragTrap(std::string name) {
    std::cout << name << ": Hey everybody! Check out my package!" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeAttackDamagePoints = 30;
    this->_rangedAttackDamagePoints = 20;
    this->_armorDamageReductionPoints = 5;
    this->_vaulhunterDamagePoints = 0;
    this->_slapDamagePoints = 1;
    this->_laserDamagePoints = 42;
    this->_kissDamagePoints = 99;
    return ;
}

/*
** Operators
*/

FragTrap    &FragTrap::operator= (FragTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_level = rhs._level;
	this->_meleeAttackDamagePoints = rhs._meleeAttackDamagePoints;
	this->_rangedAttackDamagePoints = rhs._rangedAttackDamagePoints;
	this->_armorDamageReductionPoints = rhs._armorDamageReductionPoints;
	this->_vaulhunterDamagePoints = rhs._vaulhunterDamagePoints;
  this->_slapDamagePoints = rhs._slapDamagePoints;
  this->_laserDamagePoints = rhs._laserDamagePoints;
  this->_kissDamagePoints = rhs._kissDamagePoints;
  return (*this);
}

/*
** Attacks
*/

void        FragTrap::meleeAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with melee, causing " << this->_meleeAttackDamagePoints \
              << " points of damage!" << std::endl;
}

void        FragTrap::rangedAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " at range, causing " << this->_rangedAttackDamagePoints \
              << " points of damage!" << std::endl;
}

void        FragTrap::slapAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " slaps " << target \
              << " causing " << this->_slapDamagePoints \
              << " points of damage!" << std::endl;
}

void        FragTrap::laserAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with his lasers causing " << this->_laserDamagePoints \
              << " points of damage!" << std::endl;
}

void        FragTrap::kissAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->_name << " kisses " << target \
              << " gently causing (way too much) " << this->_kissDamagePoints \
              << " points of damage!" << std::endl;
}

/*
** Damage calculations
*/

void        FragTrap::takeDamage(unsigned int amount) {
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

void        FragTrap::beRepaired(unsigned int amount) {
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

/*
** Random attacks
*/

void        FragTrap::vaulthunter_dot_exe(std::string const &target) {
  int   random;

  if (this->_energyPoints < 25) {
        std::cout << this->_name << ": I need more energy... >.<" << std::endl;
        std::cout << "Energy points needed: " << 25 - this->_energyPoints \
                  << std::endl;
  }
  else {
        this->_energyPoints -= 25;
        srand(time(NULL));
        random = rand() % 5;
        if (random == 0) {
          FragTrap::rangedAttack(target);
          this->_vaulhunterDamagePoints = getRangedAttackDamage();
        }
        else if (random == 1) {
          FragTrap::meleeAttack(target);
          this->_vaulhunterDamagePoints = getMeleeAttackDamage();
        }
        else if (random == 2) {
          FragTrap::slapAttack(target);
          this->_vaulhunterDamagePoints = getSlapDamage();
        }
        else if (random == 3) {
          FragTrap::laserAttack(target);
          this->_vaulhunterDamagePoints = getLaserDamage();
        }
        else if (random == 4) {
          FragTrap::kissAttack(target);
          this->_vaulhunterDamagePoints = getKissDamage();
        }
            
  }
}

/*
** Get methods
*/

std::string     FragTrap::getName(void) {
    return (this->_name);
}

unsigned int      FragTrap::getMeleeAttackDamage(void)  {
    return (this->_meleeAttackDamagePoints);
}

unsigned int      FragTrap::getRangedAttackDamage(void) {
    return (this->_rangedAttackDamagePoints);
}

unsigned int      FragTrap::getArmorDamageReduction(void)  {
    return (this->_armorDamageReductionPoints);
}

unsigned int      FragTrap::getVaulHunter_dot_exeDamage(void) {
    return (this->_vaulhunterDamagePoints);
}

unsigned int      FragTrap::getSlapDamage(void) {
    return (this->_slapDamagePoints);
}

unsigned int      FragTrap::getLaserDamage(void) {
    return (this->_laserDamagePoints);
}

unsigned int      FragTrap::getKissDamage(void) {
    return (this->_kissDamagePoints);
}

unsigned int      FragTrap::getHealthPoints(void) {
  return (this->_hitPoints);
}
