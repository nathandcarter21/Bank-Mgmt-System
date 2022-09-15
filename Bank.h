#ifndef BANK_MGMT_SYSTEM_BANK_H
#define BANK_MGMT_SYSTEM_BANK_H

#include <iostream>
#include <vector>
#include "User.h"

class Bank {
private:
	std::vector<User *> users;
	User *currUser;
	bool signedIn;
public:
	Bank(std::vector<User *> users);

	void PrintAllUsers();

	void PrintCurrUser();

	void CreateNewUser();

	void UserSignIn();

	void UserSignOut();

	void Deposit();

	void Withdraw();
};


#endif //BANK_MGMT_SYSTEM_BANK_H
