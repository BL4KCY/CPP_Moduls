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
	if (!infile)
		return (std::cout << fileName << ": " << strerror(errno) << std::endl, 1);
	std::ofstream	oufile((fileName + ".replace").c_str());
	if (!oufile)
		return (std::cout << fileName + ".replace: " << strerror(errno) << std::endl, 1);
	check_swap(infile, oufile, s1, s2);

	infile.close();
	oufile.close();
	return 0;
}
