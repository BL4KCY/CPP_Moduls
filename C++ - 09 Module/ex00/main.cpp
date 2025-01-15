#include "BitcoinExchange.hpp"


void	init_database(map<string, float> &dataBase, ifstream &dataFile);
float	stof(string str);
void	action(map<string, float> &dataBase, ifstream &inputFile);

int main( int c, char **av ) {
	try {
		if (2 != c)
			throw std::logic_error("Error: could not open file.");
		ifstream	dataFile( "data.csv" );
		ifstream	inputFile( av[1] );
		if (dataFile.fail() | inputFile.fail())
			throw std::logic_error("Error: could not open file.");
		map<string, float>	dataBase;
		try
		{
			init_database(dataBase, dataFile);
			action(dataBase, inputFile);
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

void	action(map<string, float> &dataBase, ifstream &inputFile)
{
	string	line;
	std::getline(inputFile, line);
	if (line != "date | value")
		throw std::logic_error("invalid input file please use \'date | value\' format !");
	while (std::getline(inputFile, line))
	{
		
	}
	(void) dataBase;
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