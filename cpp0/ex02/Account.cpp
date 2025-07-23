#include "Account.hpp"
#include <iostream>

/*static variables*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*constructor*/
Account::Account (int initial_deposit)
{
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "[19920104_091532] index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
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

/*account operations*/

void Account::makeDeposit(int deposit){
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "[19920104_091532] index:" << _accountIndex
              << ";p_amount:" << _amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << std::endl;
}

bool Account::makeWithdrawal(int withdraw){
    if (withdraw > checkAmount() || withdraw <= 0 ){
        std::cout << "[19920104_091532] index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdraw;
    _totalAmount -= withdraw;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "[19920104_091532] index:" << _accountIndex
              << ";p_amount:" << _amount + withdraw
              << ";withdrawal:" << withdraw
              << ";amount:" << _amount
              << std::endl;
    return (true);
}

int Account::checkAmount(void) const{
    return (_amount);
}

void Account::displayStatus(void) const{
    return ;
}

void Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

Account::~Account(void){
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    std::cout << "[19920104_091532] index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}
void Account::_displayTimestamp(void){
    std::cout << "[19920104_091532] ";
}
