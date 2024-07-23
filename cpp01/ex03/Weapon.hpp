
#pragma once

#include <iostream>
#include <string>



class Weapon
{
private:
	std::string	type;
public:
	void	setType(std::string type);
	const std::string &getType(void);
};


