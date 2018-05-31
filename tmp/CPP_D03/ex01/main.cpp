#include "ScavTrap.hpp"

int main(void) {
    std::cout << "- 42 Arena -"<< std::endl;
    ScavTrap    zaz("Zaz");
    ScavTrap    thor("Thor");

    std::cout << std::endl << "Zaz's turn: " << std::endl;
    zaz.meleeAttack(thor.getName());
    thor.takeDamage(zaz.getMeleeAttackDamage());
    std::cout << "-----" << std::endl;

    std::cout << std::endl << "Thor's turn: " << std::endl;
    thor.rangedAttack(zaz.getName());
    zaz.takeDamage(thor.getRangedAttackDamage());
    std::cout << "-----" << std::endl;

    std::cout << std::endl << "Zaz's turn, heals himself then challenges his enemy: " << std::endl;
    zaz.beRepaired(50);
    zaz.challengeNewcomer(thor.getName());
    std::cout << "-----" << std::endl;
    return (0);
}