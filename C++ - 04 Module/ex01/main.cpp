#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << "_________| array test |_________" << std::endl;

	Animal* array[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
	{
		delete array[i];
	}

	std::cout << "_________| end array test |_________" << std::endl;

	delete j;//should not create a leak
	delete i;
	return 0;
}
