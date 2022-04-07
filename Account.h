//
// Created by PAVAN 
//

#ifndef BANK_MANAGEMENT_ACCOUNT_H
#define BANK_MANAGEMENT_ACCOUNT_H

#include <iostream>
#include <string>

class Account {

private:
    unsigned  AccountNumber;
    std::string AccountHolder;
    unsigned MoneyDeposited;
    short AccountType;
    unsigned DepositLimit;
    short PIN;

public:

    void InitialiseDeposit();

    void SaveAccountHolder(std::string name);

    void SaveAccountNumber(unsigned number);

    void SaveAccountType(short type);

    void DepositMoney(unsigned amount);

    void WithdrawMoney(unsigned amount);

    void SavePIN(short pin);

    unsigned ReturnAccountNumber();

    std::string ReturnAccountHolder();

    unsigned CheckBalance();

    short ReturnPIN();

    unsigned ReturnDepositLimit();

    short ReturnAccountType();
};


#endif //BANK_MANAGEMENT_ACCOUNT_H
