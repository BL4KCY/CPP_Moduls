#include "Harl.hpp"


Harl::Harl(void)
{
	std::cout << GREEN << "Harl is here!" << RESET << std::endl;
}

Harl::~Harl(void)
{
	std::cout << RED << "Harl is gone! " << RESET << std::endl;
}

void Harl::complain(std::string level)
{
	void	(Harl::*arr_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	arr_str[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (level == arr_str[i])
		{
			(this->*arr_ptr[i])();
			break;
		}
	}
}

void Harl::debug(void) {
	std::cout << MAGENTA << "{DEBUG}: " << RESET;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info(void) {
	std::cout << GREEN << "{INFO}: " << RESET;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning(void) {
	std::cout << YELLOW << "{WARNING}: " << RESET;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error(void) {
	std::cout << RED << "{ERROR}: " << RESET;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
