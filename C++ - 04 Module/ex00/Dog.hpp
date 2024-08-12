#pragma once

#include "Animal.hpp"

//_____________| Dog Class|_______________//
class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &copy);
	Dog&	operator=(const Dog &copy);
	~Dog();

	void	makeSound() const;
	std::string	getType( void ) const;
	void		setType(std::string type);
};
