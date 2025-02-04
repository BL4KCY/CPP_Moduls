#include "RPN.hpp"

void	calculateRPN(string input);

double	do_op(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::runtime_error("division by zero !!");
		return a / b;
	default:
		throw std::runtime_error("invalid operator !!");
	}
}

int main( int c, char **av ) {
	string	input;
	try {
		if (c != 2) {
			throw std::runtime_error("need 1 argement, try again !!");
		}
		input = av[1];
		calculateRPN(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}

void	calculateRPN(string input)
{
	string::iterator	end = std::remove(input.begin(), input.end(), ' ');
	input.erase(end, input.end());
	if (input.empty())
		throw std::runtime_error("empty string !!");
	stack<double>		stack;
	string				operators = "+-*/";
	string				result;

	for (size_t i = 0; i < input.size(); i++) {
		if (isdigit(input[i])) {
			stack.push(input.at(i) - '0');
		}
		else if (operators.find(input[i]) != string::npos) {
			if (stack.size() < 2)
				throw std::runtime_error("not enough operands !!");
			double	b = stack.top();
			stack.pop();
			double	a = stack.top();
			stack.pop();
			stack.push(do_op(a, b, input[i]));
		}
		else
			throw std::runtime_error("invalid character !!");
	}
	if (stack.size() != 1)
		throw std::runtime_error("too many operands !!");
	cout << stack.top() << endl;
}
