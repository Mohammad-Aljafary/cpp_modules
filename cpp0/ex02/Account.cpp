#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdraw){
    if (withdraw > checkAmount() || withdraw <= 0 ){
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdraw;
    _totalAmount -= withdraw;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount + withdraw
              << ";withdrawal:" << withdraw
              << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return (true);
}

int Account::checkAmount(void) const{
    return (_amount);
}

void Account::displayStatus(void) const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}
void Account::_displayTimestamp(void){
    std::time_t now = std::time(NULL);
    if (now == -1) {
        std::cerr << "Failed to get current time." << std::endl;
        return;
    }
    std::tm* localTime = std::localtime(&now);
    std::cout << "["
              << (localTime->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (localTime->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << localTime->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << localTime->tm_hour
              << std::setfill('0') << std::setw(2) << localTime->tm_min
              << std::setfill('0') << std::setw(2) << localTime->tm_sec
              << "] ";
}
