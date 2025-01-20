#ifndef DATE_HPP
# define DATE_HPP
#include "BitcoinExchange.hpp"

class Date
{
	
private:
	const string	date;
	bool			isLeapYear;
	int				year;
	int				month;
	int				day;
public:
	Date(void);
	~Date(void);
	Date(string date);
	Date	&operator=(Date &date);
	string	getDate(void) const;
};

#endif // DATE_HPP
