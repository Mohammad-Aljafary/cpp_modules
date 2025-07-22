#include "Account.hpp"


/*constructor*/
Account::Account (int initial_deposit)
{
    _amount = initial_deposit;
}

/*get functions*/
int Account::getNbAccounts(){
    return (_nbAccounts);
}

int Account::getTotalAmount(){
    return (_totalAmount);
}

int Account::getNbDeposits(){
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(){
    return (_totalNbWithdrawals);
}