
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

