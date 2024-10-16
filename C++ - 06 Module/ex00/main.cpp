#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		cout << "Usage: ./convert [value]" << endl;
		return 1;
	}
	try
	{	
		string value = argv[1];
		ScalarConverter::convert(value);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
