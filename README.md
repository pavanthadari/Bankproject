# Bank_Management

### User guide : 

* *main.cpp* , *Account.h* and *Account.cpp* should be saved in same directory. Running *main.cpp* launches the console. 
* Navigation can be done by entering appropriate integers only.
* You need to create an account by choosing appropriate option in the home page.
* Yo can login in to an existing using the account number and password.
* Money Withdrawal and deposition can be easily done after login.
* Account Holder's name and PIN are changeable.


### Code Structure :
* The `class Account` is defines conveniently in "*Account.h*" and "*Account.cpp*".
* All the variables are kept `private` and accessed through `public` functions.
* The home page is ran in a loop until **quit** option is selected.
* All the `Account`s are stored in an array of size 10000. (`vector` was not used as it caused a bit confusion.)
* The navigation system was created using `if` and `else` statements on the options entered.
* No constructor was defined in `class Account`; a function `void InitialiseDeposit` was defined instead.
* Number of accounts is tracked by a `unsigned` type variable `accounts` by increasing it one, each time an account is created.
* Graphical output should have been given by using certain libraries in C++. This code lacks in that aspect.
* Password management is not at all secure. No hashing is used.
