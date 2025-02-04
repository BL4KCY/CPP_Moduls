#include "BitcoinExchange.hpp"

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

bool	isValidLine(string line, float &input_value, string &input_date)
{
	string	value;
	int32_t	comma = 0;
	bool	sign = false;
	
	if (line.length() < 14)
		throw std::logic_error("Error: bad input");
	if (line.substr(10, 3) != " | ")
		throw std::logic_error("Error: bad input");
	Date date(line.substr(0, 10));
	value = line.substr(13);
	if (value.at(0) == '-'){
		sign = true;
	}
	for (size_t i = 0; i < value.length();i++){
		if (value.at(i) == '.'){
			comma++;
			if (comma > 1){
				throw std::logic_error("Error: bad input");
			}
			continue;
		}
		if (sign && !i){
			continue;
		}
		if (!std::isdigit(value.at(i))){
			throw std::logic_error("Error: bad input");
		}
	}
	input_value = std::atof(value.c_str());
	input_date = date.getDate();
	return true;
}

void	action(map<string, float> &dataBase, ifstream &inputFile)
{
	float	input_value;
	string	input_date;
	map<string, float>::iterator it;
	string	line;
	std::getline(inputFile, line);
	if (line != "date | value") {
		throw std::logic_error("invalid input file please use \'date | value\' format !");
	}
	while (std::getline(inputFile, line)) {
		try
		{
			isValidLine(line, input_value, input_date);
			if (input_value > 1000){
				cerr << "Error: too large a number." << endl;
				continue;
			}
			if(input_value < 0){
				cerr << "Error: not a positive number." << endl;
				continue;
			}
			it = dataBase.lower_bound(line.substr(0, 10));
			if (it == dataBase.end()){
				it = dataBase.begin();
				it++;
			}
			if (it != dataBase.begin()){
				--it;
			}
			cout << input_date << " => " << input_value << " = " << (input_value * it->second) << endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " => " << line << '\n';
		}
	}
	(void) dataBase;
}

void	init_database(map<string, float> &dataBase, ifstream &dataFile)
{
	if (dataFile.peek() == EOF){
		cerr <<  "empty file !!!" << endl;
		exit(EXIT_FAILURE);
	}
	string	line;
	while (std::getline(dataFile, line)) {
		dataBase[(line.substr(0 ,line.find_first_of(',')))] = ::stof(line.substr(line.find_first_of(',') + 1));
	}
}

float	stof(string str)
{
	float	value;
	istringstream	iss(str);
	iss >> value;
	return value;
}