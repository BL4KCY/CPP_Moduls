#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Created" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	this->type = copy.type;
}

Cat&	Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	return (*this);
}

Cat::~Cat()
{
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
