/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:34:50 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/14 12:30:51 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_totalAmount = initial_deposit;
	if (_totalAmount > 0)
		_totalNbDeposits = 1;
	return ;
}

Account::Account( void )
{
	return ;
}

Account::~Account( void )
{
	return ;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _nbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	
}
void	Account::displayAccountsInfos( void )
{
	
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_totalNbDeposits++;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _totalAmount)
		return false;
	
	_totalAmount -= withdrawal;
	return true;
}

int		Account::checkAmount( void ) const
{
	return _totalAmount;
}

void	Account::displayStatus( void ) const
{
	return ;
}
