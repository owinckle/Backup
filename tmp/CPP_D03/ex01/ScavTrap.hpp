#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>

class ScavTrap {
public:
    // Constructors and destructors
    ScavTrap(void);
    ~ScavTrap(void);
    ScavTrap(std::string);
    // Operators
    ScavTrap        &operator=(ScavTrap const &rhs);
    // Damage methods
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    // Attack methods
    void            meleeAttack(std::string const &target);
    void            rangedAttack(std::string const &target);
    void            slapAttack(std::string const &target);
    void            laserAttack(std::string const &target);
    void            kissAttack(std::string const &target);
    // Random attack methods
    void            challengeNewcomer(std::string const &target);
    // Get methods
    std::string     getName(void);
    unsigned int    getMeleeAttackDamage(void);
    unsigned int    getRangedAttackDamage(void);
    unsigned int    getArmorDamageReduction(void);
    unsigned int    getSlapDamage(void);
    unsigned int    getLaserDamage(void);
    unsigned int    getKissDamage(void);
    unsigned int    getHealthPoints(void);
    std::string     getChallenge(void);

private:
    // Player attributes
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _maxHitPoints;
    unsigned int    _energyPoints;
    unsigned int    _maxEnergyPoints;
    unsigned int    _level;
    // Damage points
    unsigned int    _meleeAttackDamagePoints;
    unsigned int    _rangedAttackDamagePoints;
    unsigned int    _armorDamageReductionPoints;
    unsigned int    _slapDamagePoints;
    unsigned int    _laserDamagePoints;
    unsigned int    _kissDamagePoints;
    std::string     _challenge;
};

#endif