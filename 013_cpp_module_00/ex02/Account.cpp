/*
    Resultado de la compilacion de "tests.cpp":

    ❯ c++ -Wall -Wextra -Werror -std=c++98 tests.cpp
    /usr/bin/ld: /tmp/tests-f0deda.o: in function `main':
    tests.cpp:(.text+0x250): undefined reference to `Account::displayAccountsInfos()'
    /usr/bin/ld: tests.cpp:(.text+0x281): undefined reference to `Account::displayStatus() const'
    /usr/bin/ld: tests.cpp:(.text+0x408): undefined reference to `Account::makeDeposit(int)'
    /usr/bin/ld: tests.cpp:(.text+0x4d2): undefined reference to `Account::displayAccountsInfos()'
    /usr/bin/ld: tests.cpp:(.text+0x503): undefined reference to `Account::displayStatus() const'
    /usr/bin/ld: tests.cpp:(.text+0x68a): undefined reference to `Account::makeWithdrawal(int)'
    /usr/bin/ld: tests.cpp:(.text+0x6c0): undefined reference to `Account::displayAccountsInfos()'
    /usr/bin/ld: tests.cpp:(.text+0x6f1): undefined reference to `Account::displayStatus() const'
    /usr/bin/ld: /tmp/tests-f0deda.o: in function `void std::_Construct<Account, int>(Account*, int const&)':
    tests.cpp:(.text._ZSt10_ConstructI7AccountiEvPT_RKT0_[_ZSt10_ConstructI7AccountiEvPT_RKT0_]+0x1b): undefined reference to `Account::Account(int)'
    /usr/bin/ld: /tmp/tests-f0deda.o: in function `void std::_Destroy<Account>(Account*)':
    tests.cpp:(.text._ZSt8_DestroyI7AccountEvPT_[_ZSt8_DestroyI7AccountEvPT_]+0x11): undefined reference to `Account::~Account()'
    clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
    Constructor personalizado:

    [19920104_091532] index:0;amount:42;created
*/
Account::Account(int initial_deposit)
{
    this->_displayTimestamp();
    this->_accountIndex = this->_nbAccounts;
    std::cout << "index:" << this->_accountIndex << ";";
    this->_nbAccounts += 1;
    this->_amount = initial_deposit;
    std::cout << "amount:" << this->_amount << ";";
    this->_totalAmount += initial_deposit;
    std::cout << "created" << std::endl;
};

/*
    Destructor personalizado:

    [19920104_091532] index:0;amount:47;closed
*/
Account::~Account()
{

    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
};

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int Account::checkAmount() const
{
    return (this->_amount);
}

/*
bool	makeWithdrawal( int withdrawal );
Account( void );
*/

/*
    [19920104_091532]
*/
void Account::_displayTimestamp()
{
    std::time_t now;

    now = std::time(NULL);
    std::cout << "[" << std::put_time(localtime(&now), "%Y%m%d_%H%M%S") << "] ";
}

/*
    [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}

/*
    [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";"; // AQUI HAY UN FALLO!
    std::cout << "deposits;" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

/*
    [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void	Account::makeDeposit(int deposit)
{
    this->_nbDeposits += 1;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_totalAmount = this->checkAmount() + deposit;
    std::cout << "amount:" << this->_totalAmount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/*
    [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool	Account::makeWithdrawal(int withdrawal)
{
    this->_nbWithdrawals += 1;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->checkAmount() << ";";
    if (withdrawal > this->checkAmount())
    {
        std::cout << "withdrawal:refused" << std::endl;    
        return (false);
    }
    std::cout << "withdrawal:" << withdrawal << ";";
    this->_totalAmount = this->checkAmount() - withdrawal;
    std::cout << "amount:" << this->_totalAmount << ";";
    std::cout << "nb_withdrawal:" << this->_nbWithdrawals << std::endl;
    return (true);
}
