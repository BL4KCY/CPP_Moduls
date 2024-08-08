#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	setHitPoint(copy.getHitPoint());
	setEnergyPoint(copy.getEnergyPoint());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "FragTrap assinged" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << getName() << " attack " << target << " causing " << this->getAttackDamage() << " points of damage" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " give me five" << std::endl;
}
