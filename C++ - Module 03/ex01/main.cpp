#include "ScavTrap.hpp"



int main(void)
{
	ScavTrap A;
	ScavTrap B("B");
	ScavTrap C = B;
	A = C;

	C.guardGate();

	C.attack("A");

	return (0);
}
