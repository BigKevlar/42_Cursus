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

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts;
        this->_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
};

Account::~Account() {};

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

/*
void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;
Account( void );
*/

/*
    Ponemos el tiempo como en la version del archivo de registro:

        [19920104_091532]
*/
void _displayTimestamp()
{
    std::time_t now;

    now = std::time(NULL);
    std::cout << "[" << std::put_time(localtime(&now), "%Y%m%d_%H%M%S ") << "]";
}

/*
    Ponemos el registro total cuando llegamos a 8 cuentas creadas:

        [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits;" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

/*
    [19920104_091532] index:0;amount:42;created
*/
void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << "; ";
    std::cout << "amount:" << this->checkAmount() << "; ";
    std::cout << "deposits:" << this->_nbDeposits << "; ";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
