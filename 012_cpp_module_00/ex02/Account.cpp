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

