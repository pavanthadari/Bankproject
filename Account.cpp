//
// Created by PAVAN
//

#include <iostream>
#include <string>

#include "Account.h"


void Account::SaveAccountHolder(std::string name) {
    this->AccountHolder = name;

}

void Account::SaveAccountNumber(unsigned number) {
    this->AccountNumber = number;

}

void Account::SaveAccountType(short type) {
    this->AccountType = type;

}

void Account::InitialiseDeposit() {
    this->MoneyDeposited = 0;
    if(this->AccountType == 4) this->DepositLimit = 50000;
    else this->DepositLimit = 100000;

}

void Account::DepositMoney(unsigned amount) {
    if(this->MoneyDeposited + amount <= this->DepositLimit) {
        this->MoneyDeposited += amount;
        std::cout << "Deposit successful.\n";
    }
    else std::cout << "Deposit unsuccessful. Collect your money.\t[exceeding limit]\n";
}

void Account::WithdrawMoney(unsigned amount) {
    if(this->MoneyDeposited > amount) {
        this->MoneyDeposited -= amount;
        std::cout << "Money is Deducted from your account. Collect your cash.\n";
    }
    else std::cout << "Withdrawal failed.\t[insufficient balance]\n";
}

void Account::SavePIN(short pin) {
    this->PIN = pin;

}

unsigned Account::ReturnAccountNumber() {
    return this->AccountNumber;
}

unsigned Account::CheckBalance() {
    return this->MoneyDeposited;
}

short Account::ReturnPIN() {
    return this->PIN;
}

std::string Account::ReturnAccountHolder() {
    return this->AccountHolder;
}

unsigned Account::ReturnDepositLimit() {
    return this->DepositLimit;
}

short Account::ReturnAccountType() {
    return this->AccountType;
}


