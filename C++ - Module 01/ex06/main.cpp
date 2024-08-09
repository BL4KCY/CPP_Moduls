#include "Harl.hpp"

int	compare(std::string level)
{
	std::string	arr_str[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (level == arr_str[i])
			return (i);
	}
	return (-1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Usage: " << av[0] << " <level>\n", 1);
	Harl	harl;
	std::string	level = av[1];

	switch (compare(level))
	{
		case 0:
			harl.complain("debug");
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break ;
		case 1:
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break ;
		case 2:
			harl.complain("warning");
			harl.complain("error");
			break ;
		case 3:
			harl.complain("error");
			break ;
		default:
			std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET <<  std::endl;
	}

	return 0;
}
