#ifndef RPN_HPP
# define RPN_HPP
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
# include <algorithm>

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

enum e_switch
{
	NUMBER,
	OPERATOR,
	SPACE
};

#endif // RPN_HPP