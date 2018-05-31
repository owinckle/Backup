#include "FragTrap.hpp"

int main(void) {
    std::cout << "- 42 Arena -"<< std::endl;
    FragTrap    zaz("Zaz");
    FragTrap    thor("Thor");

    std::cout << std::endl << "Zaz's turn: " << std::endl;
    zaz.meleeAttack(thor.getName());
    thor.takeDamage(zaz.getMeleeAttackDamage());
    std::cout << "-----" << std::endl;

    std::cout << std::endl << "Thor's turn: " << std::endl;
    thor.rangedAttack(zaz.getName());
    zaz.takeDamage(thor.getRangedAttackDamage());
    std::cout << "-----" << std::endl;

    std::cout << std::endl << "Zaz's turn, heals himself then attacks at random: " << std::endl;
    zaz.beRepaired(50);
    zaz.vaulthunter_dot_exe(thor.getName());
    thor.takeDamage(zaz.getVaulHunter_dot_exeDamage());
    std::cout << "-----" << std::endl;
	
    std::cout << std::endl << "Thor's turn, tries to use a random attack but somehow fucks up --\": " << std::endl;
    thor.vaulthunter_dot_exe(thor.getName());
    thor.takeDamage(thor.getVaulHunter_dot_exeDamage());
    std::cout << "-----" << std::endl;
    return (0);
}