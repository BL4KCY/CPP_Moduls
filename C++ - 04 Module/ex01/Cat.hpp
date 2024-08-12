#pragma once

#include "Animal.hpp"

//_____________| Cat Class|_______________//
class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat &copy);
	Cat&	operator=(const Cat &copy);
	~Cat();

	void	makeSound() const;
	std::string	getType( void ) const;
	void		setType(std::string type);
};
