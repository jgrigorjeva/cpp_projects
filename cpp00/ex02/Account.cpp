#include "Account.hpp"

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
}