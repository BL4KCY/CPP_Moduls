#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n_____________| WrongAnimal |_______________\n" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << wrongcat->getType() << " " << std::endl;

	wrongcat->makeSound();
	meta2->makeSound();

	delete meta2;
	delete wrongcat;
	return 0;
}
