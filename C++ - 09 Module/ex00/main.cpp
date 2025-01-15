#include "BitcoinExchange.hpp"


void	init_database(map<string, float> &dataBase, ifstream &dataFile);
float	stof(string str);

int main( int c, char **av ) {
	try {
		if (2 != c)
			throw std::logic_error("Error: could not open file.");
		ifstream	dataFile( av[1] );
		if (dataFile.fail())
			throw std::logic_error("Error: could not open file.");
		map<string, float>	dataBase;
		try
		{
			init_database(dataBase, dataFile);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}

void	init_database(map<string, float> &dataBase, ifstream &dataFile)
{
	string	line;
	while (std::getline(dataFile, line))
	{
		dataBase[(line.substr(0 ,line.find_first_of(',')))] = stof(line.substr(line.find_first_of(',') + 1));
	}
}

float	stof(string str)
{
	float	value;
	istringstream	iss(str);
	iss >> value;
	return value;
}