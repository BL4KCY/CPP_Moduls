#include "easyfind.hpp"




int main( void ) {

	std::list<int> vec;
	for (int i  = 0; i < 10; i++){
		vec.push_back(i);
	}

	try
	{
		int value = easyfind(vec, 6);

		std::cout << "The value :" << value << std::endl;

		value = easyfind(vec, 53);

		std::cout << "The value :" << value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
