
#pragma once
#include <iostream>
#include <string>

// colors
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl( void );
	~Harl( void );
	void	complain( std::string level );
};
