#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <map>
# include <fstream>
# include <exception>
# include <sstream>
# include <utility>
# include <cstdlib>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::map;
using std::istringstream;

# include "Date.hpp"

void	init_database(map<string, float> &dataBase, ifstream &dataFile);
float	stof(string str);
void	action(map<string, float> &dataBase, ifstream &inputFile);

#endif // BITCOINEXCHANGE_HPP