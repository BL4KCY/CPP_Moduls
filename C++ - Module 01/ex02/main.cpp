#include <iostream>
#include <string>

int main(void)
{
	std::string	man = "HI THIS IS BRAIN";
	std::string* stringPTR = &man;
	std::string& stringREF = man;


	std::cout << &man << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << man << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;


	return (0);
}
