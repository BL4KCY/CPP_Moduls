#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie newZome(name);
	newZome.announce();
}
