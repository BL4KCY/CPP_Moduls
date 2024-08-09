#include "FragTrap.hpp"


int main(void)
{
	FragTrap A;
	FragTrap B("B");
	FragTrap C = B;
	A = C;

	C.highFivesGuys();

	C.attack("A");

	return (0);
}
