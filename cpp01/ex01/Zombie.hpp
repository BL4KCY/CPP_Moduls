/* Description: Zombie class header file.
 * Member functions:
 * 	announce: Announces the zombie.
 * 	newZombie: Creates a new zombie.
 * 	randomChump: Creates a random zombie and announces it.
 */

#include <iostream>
#include <string>

#pragma once

// class definition

class Zombie
{
private:
	std::string	name;
public:
	void	announce( void );
	void	setName(std::string name);
	Zombie(std::string name = "Unamed Zombie");
	~Zombie();
};

// Function prototypes

Zombie*	zombieHorde( int N, std::string name );

// end of Zombie.hpp
