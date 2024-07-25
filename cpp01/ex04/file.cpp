#include "file.hpp"

void	check_swap(std::ifstream &infile, std::ofstream &oufile, std::string s1, std::string s2)
{
	char		c;
	std::string	buff;

	c = infile.get();
	while ( c != EOF )
	{
		if (c == s1.c_str()[0])
		{
			for (int i = 0; c == s1.c_str()[i] && c != EOF; i++)
			{
				buff += c;
				c = infile.get();
			}
			if (s1 == buff)
			{
				oufile.write(s2.c_str(), s2.size());
				buff.clear();
			}
			else if (buff.size())
			{
				oufile.write(buff.c_str(), buff.size());
				buff.clear();
			}
			if (c != s1.c_str()[0] && c != EOF)
				oufile.put(c);
		}
		else
			oufile.put(c);
		if (c != s1.c_str()[0])
			c = infile.get();
	}
}


