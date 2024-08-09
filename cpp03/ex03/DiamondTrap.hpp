#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &diamondTrap);

	void attack(std::string const & target);
	void whoAmI();
};
