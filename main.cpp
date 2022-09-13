#include <iostream>
#include "Bank.h"
#include "User.h"

int main() {
	std::string names[] = {"Nathan Carter", "Jane Doe", "Joe Smith"};
	std::string emails[] = {"jnlcarter5@gmail.com", "JaneDoe@hotmail.com", "JoeSmith@gmail.com"};
	std::string passwords[] = {"password", "PASSWORD", "pass123"};
	double checkingBals[] = {45.65, 23.98, 78.99};
	double savingsBals[] = {9525.24, 4567.78, 958.29};

	std::vector<User *> users;

	for (int i = 0; i < 3; i++) {
		User *user = new User(names[i], emails[i], passwords[i], i + 1, checkingBals[i], savingsBals[i]);
		users.push_back(user);
	}
	Bank bank(users);
	std::string input;
	bool continueLoop = true;

	while (continueLoop) {
		std::cout << "Please select an action\n" <<
				  "N for New Account\n" <<
				  "B for Bank Information\n" <<
				  "I for User Information\n" <<
				  "D to Deposit Funds\n" <<
				  "S to Sign In\n" <<
				  "O to Sign Out\n" <<
				  "Q to quit\n";
		std::cin >> input;
		std::cout << std::endl;
		if (input == "Q") {
			continueLoop = false;
		} else if (input == "N") {
			bank.CreateNewUser();
		} else if (input == "B") {
			bank.PrintAllUsers();
		} else if (input == "I") {
			bank.PrintCurrUser();
		} else if (input == "D") {
			bank.Deposit();
		} else if (input == "S") {
			bank.UserSignIn();
		} else if (input == "O") {
			bank.UserSignOut();
		}
	}

	std::cout << "Goodbye\n";

	return 0;
}
