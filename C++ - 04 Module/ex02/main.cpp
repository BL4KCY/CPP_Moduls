#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal test;


	delete j;//should not create a leak
	delete i;
	

	std::cout << "_________| array test |_________" << std::endl;

	Animal* array[] =
	{
		new Dog(),
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
		new Cat()
	};

	for (unsigned long i = 0; i < sizeof(array) / sizeof(*array); i++)
	{
		std::cout << "__| " << i << " |__" << std::endl;
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
