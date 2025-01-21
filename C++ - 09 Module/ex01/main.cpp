#include "RPN.hpp"

string	check_input(string input);


int main( int c, char **av ) {
	string	input;
	try {
		if (c != 2) {
			throw std::runtime_error("need 1 argement, try again !!");
		}
		input = check_input(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}

string	check_input(string input)
{
	e_switch status = SPACE;
	e_switch prev_status = NUMBER;
	if (input.length() < 5){
		throw std::runtime_error("invalid input, try again !!");
	}
	if (!std::isdigit(input.at(0)) && !std::isdigit(input.at(2)) && ' ' != input.at(1)){
		throw std::runtime_error("invalid input, try again !!");
	}
	for (size_t i = 3; i < input.length();i++)
	{
		if (status == SPACE){
			if (' ' != input.at(i)){
				throw std::runtime_error("invalid input, try again !!");
			}
			status = (prev_status == NUMBER) ? OPERATOR : NUMBER;
			prev_status = SPACE;
		}
		else if (status == NUMBER){
			if (!std::isdigit(input.at(i))){
				throw std::runtime_error("invalid input, try again !!");
			}
			status = SPACE;
			prev_status = NUMBER;
		}
		else if (status == OPERATOR){
				cout << "index: "<< i << " " << endl;
			if (string::npos == string("+-*/").find(input.at(i))){
				throw std::runtime_error("invalid input, try again !!");
			}
			if (input.at(i) == '/' && input.at(i - 2) == '0'){
				throw std::runtime_error("invalid input, div by zero, try again !!");
			}
			status = SPACE;
			prev_status = OPERATOR;
		}
	}
	if (status != SPACE || OPERATOR != prev_status){
		throw std::runtime_error("invalid input, try again !!");
	}
	return input;
}