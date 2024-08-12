#include "Zombie.hpp"



int main(void)
{
	randomChump("bokhancha");

	Zombie* zli9 = newZombie("7afozli9");

	zli9->announce();

	delete zli9;
}

