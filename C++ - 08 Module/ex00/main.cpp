#include "easyfind.hpp"




int main( void ) {

	std::list<int> vec;
	for (int i  = 0; i < 10; i++){
		vec.push_back(i);
	}

	try
	{
		index indx = easyfind(vec, 6);

		std::cout << "The index :" << indx << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
