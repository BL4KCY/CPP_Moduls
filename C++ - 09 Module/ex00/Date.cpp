#include "Date.hpp"


Date::Date(string	date) : date(date)
{
	const int	YearDays[2][12] = {
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
		{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
	};
	for(int i = 0; i < 4; i++) {
		if (0 == std::isdigit(date.at(i))) {
			throw std::runtime_error("Error: bad input");
		}
	}
	for (int i = 0; i < 2;i++) {
		if (0 == std::isdigit(date.at(5 + i)) || 0 == std::isdigit(date.at(8 + i))) {
			throw std::runtime_error("Error: bad input");
		}
	}
	if (date.at(4) != '-' || date.at(7) != '-') {
			throw std::runtime_error("Error: bad input");
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1 || month < 1 || 12 < month)
		throw std::runtime_error("Error: bad input");
	isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (day > YearDays[isLeapYear][month - 1])
		throw std::runtime_error("Error: bad input");
}

Date::Date(void) : date(string("1446-07-17"))
{
	this->day = 17;
	this->month = 7;
	this->year = 1446;
}

Date&	Date::operator=(Date &date)
{
	(void)date;
	return (*this);
}

string	Date::getDate(void) const
{
	return (date);
}

Date::~Date(void)
{

}