#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Created" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << "Cat copied" << std::endl;
}

Cat&	Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destroyed" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow 😺" << std::endl;
}

std::string	Cat::getType( void ) const
{
	return (this->type);
}

void		Cat::setType(std::string type)
{
	this->type = type;
}
