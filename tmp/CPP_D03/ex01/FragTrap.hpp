#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

class FragTrap {
public:
    // Constructors and destructors
    FragTrap(void);
    ~FragTrap(void);
    FragTrap(std::string);
    // Operators
    FragTrap        &operator=(FragTrap const &rhs);
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
    void            vaulthunter_dot_exe(std::string const &target);
    // Get methods
    std::string     getName(void);
    unsigned int    getMeleeAttackDamage(void);
    unsigned int    getRangedAttackDamage(void);
    unsigned int    getArmorDamageReduction(void);
    unsigned int    getVaulHunter_dot_exeDamage(void);
    unsigned int    getSlapDamage(void);
    unsigned int    getLaserDamage(void);
    unsigned int    getKissDamage(void);
    unsigned int    getHealthPoints(void);

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
    unsigned int    _vaulhunterDamagePoints;
    unsigned int    _slapDamagePoints;
    unsigned int    _laserDamagePoints;
    unsigned int    _kissDamagePoints;
};

#endif