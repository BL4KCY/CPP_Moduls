
#include <iostream>
#include <string>

#pragma once

// class definition

class Zombie
{
private:
	std::string	name;
public:
	void announce( void );
	Zombie(std::string name);
	~Zombie();
};

// Function prototypes

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

// end of Zombie.hpp
