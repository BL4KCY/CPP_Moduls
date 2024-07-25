#include "file.hpp"

void	check_swap(std::ifstream &infile, std::ofstream &oufile, std::string s1, std::string s2)
{
	std::string	buff;

	while (getline(infile, buff))
	{
		while (buff.find(s1) != std::string::npos)
		{
			buff = buff.substr(0, buff.find(s1)) + s2 + buff.substr(buff.find(s1) + s1.size());
		}
		oufile << buff;
		if (!infile.eof())
			oufile << std::endl;
	}
}

