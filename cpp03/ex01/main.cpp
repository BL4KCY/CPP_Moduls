#include "ClapTrap.hpp"






int main(void)
{
	ClapTrap claptrap("Teo");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;
	ClapTrap claptrap4;
	claptrap4 = claptrap;

	std::cout << std::endl;
	std::cout << std::endl;

	claptrap.attack("enemy");
	claptrap.takeDamage(9);
	claptrap.attack("enemy");
	claptrap.beRepaired(10);
	claptrap.attack("enemy");
	return (0);
}
