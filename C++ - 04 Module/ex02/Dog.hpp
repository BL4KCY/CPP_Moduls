
#pragma once

//_____________| headers |_________________//
#include "Animal.hpp"
#include "Brain.hpp"

//_____________| Dog Class |_______________//
class Dog: public Animal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &copy);
	Dog&	operator=(const Dog &copy);
	~Dog();

	void	makeSound() const;
	std::string	getType( void ) const;
	void		setType(std::string type);
};
