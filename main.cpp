//
// Created by PAVAN 
//

#include <iostream>
#include <string>
#include "Account.h"

Account CreateAccount(int accounts) {
    Account NewAccount;

    NewAccount.SaveAccountNumber(accounts + 1);

    std::cout << "Enter the name of account holder.\n";
    std::string name;
    std::cin >> name;
    NewAccount.SaveAccountHolder(name);

    std::cout << "Enter account holder's age. \t";
    short age;
    std::cin >> age;
    while(age <= 14 || age > 150) {
        std::cout << "Enter valid age.\n";
        std::cin >> age;
    }
    if(age > 60) {
        NewAccount.SaveAccountType(3);
        std::cout << "\nSenior Citizen Account is selected.\n";
    }
    else if(age > 14 && age < 19) {
        NewAccount.SaveAccountType(4);
        std::cout << "\nTeen Account is selected.\n";
    }
    else {
        std::cout
                << "\nSelect the type of account to be created.\n[1]. Savings Account\t[2]. Current Account\n[3]. Senior Citizen Account\t[4]. Teen Account\nTeen Account is for ages from 15 to 18 both inclusive.\nSenior Citizen Account is for ages greater than 60.\n";
        short type;

        std::cin >> type;
        while (type != 1 && type != 2) {
            std::cout
                    << "Enter valid number.\n[1]. Savings Account\t[2]. Current Account\n[4]. Senior Citizen Account\t[5]. Teen Account\n";
            std::cin >> type;
        }
        NewAccount.SaveAccountType(type);

    }

    NewAccount.InitialiseDeposit();

    short pin, pin2;
    std::cout << "Enter new PIN: \t";
    std::cin >> pin;
    std::cout << "Confirm the PIN: \t";
    std::cin >> pin2;
    while(pin != pin2) {
        std::cout << "Enter the PIN again. [entered PIN's do not match]\n";
        std::cout << "Enter new PIN: \t";
        std::cin >> pin;
        std::cout << "Confirm the PIN: \t";
        std::cin >> pin2;
    }
    NewAccount.SavePIN(pin);

    std::cout << "Account created successfully.\n\nYour account number is " << NewAccount.ReturnAccountNumber() << "\n\n";

    return NewAccount;
}

int main() {

    unsigned accounts;
    accounts = 0;
    Account database[10000];
    Account temp;

    while(true) {
        short option;
        std::cout << "\nWelcome to the Banking console.\nNavigate by entering respective numbers.\n\n[1]. Create new Account.\n[2]. Log in to existing account.\n[3]. Quit console.\n";

        std::cin >> option;

        if(option == 3) {
            std::cout << "Thank you.\n";
            break;
        } else if (option == 1) {
            database[accounts+1] = CreateAccount(accounts);
            accounts++;
        } else if (option == 2) {

            unsigned account_number;
            short pin, original_pin;

            std::cout << "\nAccount number : \t";
            std::cin >> account_number;
            if(account_number <= accounts) {

                original_pin = database[account_number].ReturnPIN();

                std::cout << "\nPIN : \t";
                std::cin >> pin;
                while (original_pin != pin) {
                    std::cout << "\nLogin failed.\nEnter correct login credentials.\n";
                    std::cout << "\nAccount number : \t";
                    std::cin >> account_number;
                    original_pin = database[account_number].ReturnPIN();

                    std::cout << "\nPIN : \t";
                    std::cin >> pin;

                }
                std::cout << "\nLogin successful.\n";
                short option2;

                do {
                    std::cout << "\nHello " << database[account_number].ReturnAccountHolder()
                              << "!\n[1]. Deposit Money.\t[2]. Withdraw Money.\n[3]. View Account Summary.\n[4]. Change Account Holder Name.\n[5]. Check Balance.\t[6]. Change PIN.\n[7]. Log out.\n";
                    std::cin >> option2;

                    if (option2 == 5) {
                        std::cout << "Current balance in your account is  "
                                  << database[account_number].CheckBalance()
                                  << " rupees."
                                  << std::endl;
                    }

                    unsigned cash;

                    if (option2 == 1) {
                        std::cout
                                << "\nPlease enter the amount in rupees to be deposited.\nInsert the cash in the slot opened.\n";
                        std::cin >> cash;
                        database[account_number].DepositMoney(cash);
                    }

                    if (option2 == 2) {
                        std::cout << "\nPlease enter the amount in rupees.\n";
                        std::cin >> cash;
                        database[account_number].WithdrawMoney(cash);
                    }
                    if (option2 == 4) {
                        std::cout << "\nPlease confirm.\tDo you want to change the account holder's name from \""
                                  << database[account_number].ReturnAccountHolder()
                                  << "\"?\n[1]. YES\t[2]. NO\n";
                        short option3;
                        std::cin >> option3;
                        if (option3 == 1) {
                            std::cout << "\nEnter new name. :\t";
                            std::string rename;
                            std::cin >> rename;
                            database[account_number].SaveAccountHolder(rename);
                            std::cout << "The Account Holder's name is successfully changed to \""
                                      << database[account_number].ReturnAccountHolder()
                                      << "\".\n";
                        }
                    }
                    if (option2 == 3) {

                        std::string account_type;
                        if (database[account_number].ReturnAccountType() == 1) account_type = "Savings Account";
                        if (database[account_number].ReturnAccountType() == 2) account_type = "Current Account";
                        if (database[account_number].ReturnAccountType() == 3) account_type = "Senior Citizen Account";
                        if (database[account_number].ReturnAccountType() == 4) account_type = "Teen Account";

                        std::cout << "\t\tAccount Summary\t\n\nAccount Holder's name : "
                                  << database[account_number].ReturnAccountHolder()
                                  << "\n\nAccount number        : "
                                  << database[account_number].ReturnAccountNumber()
                                  << "\n\nAccount type          : "
                                  << account_type << "\n\nDeposit Limit         : "
                                  << database[account_number].ReturnDepositLimit()
                                  << " rupees\n\nCurrent Balance       : "
                                  << database[account_number].CheckBalance()
                                  << " rupees\n\n";
                    }
                    if (option2 == 6) {
                        std::cout << "\nEnter old PIN.\t";
                        short new_pin;
                        std::cin >> new_pin;
                        if (pin == new_pin) {
                            std::cout << "\nEnter new PIN.\t";
                            std::cin >> new_pin;
                            std::cout << "\nConfirm new PIN.\t";
                            std::cin >> pin;
                            if (new_pin == pin) {
                                database[account_number].SavePIN(pin);
                                std::cout << "\nChange of PIN successful.\n";
                            } else std::cout << "\nAction aborted.\n";
                        } else std::cout << "\nAction aborted.\n";
                    }
                    else if (option2 != 7) std::cout << "\nEnter valid option.\n";


                } while (option2 != 7);

            } else std::cout << "\nYour Account does not exist. Check your Account number.\n\n";

        } else std::cout << "\n\nEnter valid option.\n\n";
    }
    return 0;
}
