#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>

// initialize static variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructor
Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_nbAccounts++;
	_totalNbDeposits = 0;

	_displayTimestamp();
	std:: cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << std::endl;
}

// destructor
Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std:: cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
}

// method to display account information
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std:: cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// method to display account status
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std:: cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

// method to make a deposit
void	Account::makeDeposit( int deposit )
{
	int		prevAmount = _amount;
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;

	_displayTimestamp();
	std:: cout << "index:" << _accountIndex
	<< ";p_amount:" << prevAmount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

// method to make a withdrawal
bool	Account::makeWithdrawal( int withdrawal )
{
	int		prevAmount = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std:: cout << "index:" << _accountIndex
		<< ";p_amount:" << prevAmount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;

	_displayTimestamp();
	std:: cout << "index:" << _accountIndex
	<< ";p_amount:" << prevAmount
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

// function to get current time
std::string	currentTime(void)
{
	char		buffer[80];
	time_t		rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	return (buffer);
}

// method to display timestamp
void	Account::_displayTimestamp( void )
{
	std:: cout << currentTime();
}

// method to check amount
int	Account::checkAmount( void ) const
{
	return (_amount);
}

// getter to get number of accounts
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

// getter to get number of deposits
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

// getter to get number of withdrawals
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

// getter to get total amount
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
