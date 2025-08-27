// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>
#include <ctime>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; //internal alias

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void ); //shows total numbers, e.g.:
                                            // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

	Account( int initial_deposit ); //creates an account and prints a message, e.g.:
                                    // [19920104_091532] index:0;amount:42;created
	~Account( void ); //closes and account and prints a message, e.g.:
                        // [19920104_091532] index:0;amount:47;closed

	void	makeDeposit( int deposit ); //makes a deposit and prints a message:
    // [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	bool	makeWithdrawal( int withdrawal ); ////makes a withdrawal and prints a message:
    // [19920104_091532] index:0;p_amount:47;withdrawal:refused
    // [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1


	int		checkAmount( void ) const;
	void	displayStatus( void ) const; //shows the stats for each account, e. g.:
    // index:0;amount:42;deposits:0;withdrawals:0


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
