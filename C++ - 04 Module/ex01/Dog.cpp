#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Created" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	this->type = copy.type;
}

Dog&	Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof 🐶" << std::endl;
}

std::string	Dog::getType( void ) const
{
	return (this->type);
}

void		Dog::setType(std::string type)
{
	this->type = type;
}
