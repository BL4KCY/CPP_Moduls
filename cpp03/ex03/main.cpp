#include "DiamondTrap.hpp"


int main(void)
{
	DiamondTrap A;
	DiamondTrap B("B");
	DiamondTrap C = B;
	A = C;

	C.highFivesGuys();

	C.attack("A");

	return (0);
}
