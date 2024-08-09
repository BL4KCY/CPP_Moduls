#include "file.hpp"

void	check_swap(std::ifstream &infile, std::ofstream &oufile, std::string s1, std::string s2)
{
	std::string	buff;
	std::string	sec_buff;

	while (getline(infile, buff))
	{
		while (buff.find(s1) != std::string::npos && !s1.empty() && s1 != s2)
		{
			sec_buff += buff.substr(0, buff.find(s1)) + s2;
			buff = buff.substr(buff.find(s1) + s1.size());
		}
		oufile << sec_buff << buff;
		if (infile)
			oufile << std::endl;
		sec_buff.clear();
	}
}

