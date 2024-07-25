#include "file.hpp"


int main(int c, char **av)
{
	// if number of arguments is not 3
	if (c != 4)
		return (std::cout << "./<bin> <fileName> <s1> <s2>\n", 1);

	std::string		fileName = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	std::ifstream	infile(fileName.c_str());
	if (infile.fail())
		return (std::cout << "fail to open: " << fileName << std::endl, 1);
	std::ofstream	oufile((fileName + ".out").c_str());
	if (oufile.fail())
		return (std::cout << "fail to open: " << fileName + ".out" << std::endl, infile.close(), 1);
	check_swap(infile, oufile, s1, s2);

	infile.close();
	oufile.close();
	return 0;
}
