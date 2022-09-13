#include "Bank.h"

Bank::Bank(std::vector<User *> users) {
	this->users = users;
	currUser = nullptr;
	signedIn = false;
}

void Bank::PrintAllUsers() {
	std::cout << "Current User\n";
	if (currUser != nullptr) {
		currUser->PrintUser();
	}
	std::cout << "\nAll users\n";
	for (auto user: users) {
		user->PrintUser();
	}
	std::cout << std::endl;
}

void Bank::CreateNewUser() {
	std::string name;
	std::string email;
	std::string password;
	std::cout << "Thank you for choosing Nathan's Banking Management System\n"
			  << "Please enter your name, email, and a password\n"
			  << "Name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Email: ";
	std::getline(std::cin, email);
	std::cout << "Password: ";
	std::getline(std::cin, password);
	for (auto user: users) {
		if (user->getEmail() == email) {
			std::cout << "Sorry, that email is already associated with an account\n";
			return;
		}
	}
	User *user = new User(name, email, password, users.size() + 1);
	users.push_back(user);
	currUser = user;
	signedIn = true;
	std::cout << "Account created successfully!\n";
	user->PrintUser();
}

void Bank::PrintCurrUser() {
	if (!signedIn) {
		std::cout << "Please sign in first!\n";
		return;
	}
	currUser->PrintUser();

}

void Bank::UserSignIn() {
	if (signedIn) {
		std::cout << "You are already signed in!\n";
		return;
	}
	std::string email;
	std::string password;
	std::cout << "Please enter your email and password\n" <<
			  "Email: ";
	std::cin >> email;
	std::cout << "Password: ";
	std::cin >> password;
	for (auto user: users) {
		if (user->getEmail() == email && user->getPassword() == password) {
			std::cout << "Sign in successful!\n\n";
			currUser = user;
			signedIn = true;
			return;
		}
	}
	std::cout << "Sorry, those credentials didn't match our records\n\n";
}

void Bank::UserSignOut() {
	if (!signedIn) {
		std::cout << "Please sign in first\n\n";
		return;
	}
	signedIn = false;
	currUser = nullptr;
}

void Bank::Deposit() {
	if (!signedIn) {
		std::cout << "Please sign in first\n\n";
		return;
	}
	double amount;
	std::string account;
	std::cout << "How much money would you like to deposit?\n" <<
			  "Amount: ";
	std::cin >> amount;
	std::cout << std::endl;
	while (amount > 250000 || amount < 1) {
		std::cout << "Sorry, the minimum amount to deposit is $1.00 and the maximum amount to deposit is $250,000"
					 ".00\nPlease enter a different number\n" <<
				  "Amount: ";
		std::cin >> amount;
		std::cout << std::endl;
	}
	std::cout << "Which account would you like to deposit $" << amount << "?\n"
			  << "S for Savings Account and C for Checking Account\n"
			  << "Account: ";
	std::cin >> account;
	if (account == "C") {
		currUser->setCheckingBal(currUser->getCheckingBal() + amount);
		std::cout << "Funds successfully transferred!\n" <<
				  "Your Checking Account balance is now $" << currUser->getCheckingBal() << std::endl << std::endl;
	} else if (account == "S") {

	} else {

	}

}
