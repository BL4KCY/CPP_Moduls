#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	delete j;//should not create a leak
	delete i;

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
	std::cout << "_________| deep copy test |_________" << std::endl;

	Cat		cat;
	Cat		cat2(cat);

	cat2.setType("cat2");
	std::cout << "cat1 type: " << cat.getType() << std::endl;
	std::cout << "cat2 type: " << cat2.getType() << std::endl;

	std::cout << "_________| end deep copy test |_________" << std::endl;

	return 0;
}
