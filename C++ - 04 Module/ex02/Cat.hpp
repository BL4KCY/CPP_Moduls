#pragma once

//_____________| Headers |________________//
#include "Animal.hpp"
#include "Brain.hpp"

//_____________| Cat Class |_______________//
class Cat: public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &copy);
	Cat&	operator=(const Cat &copy);
	~Cat();

	void	makeSound() const;
	std::string	getType( void ) const;
	void		setType(std::string type);
};
