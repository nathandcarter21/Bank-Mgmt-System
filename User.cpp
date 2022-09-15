#include <iomanip>
#include "User.h"

User::User(std::string name, std::string email, std::string password, int accountNum) {
	this->name = name;
	this->email = email;
	this->password = password;
	this->accountNum = accountNum;
	this->checkingBal = 0;
	this->savingsBal = 0;
}

User::User(std::string name, std::string email, std::string password, int accountNum, double checkingBal,
		   double savingsBal) {
	this->name = name;
	this->email = email;
	this->password = password;
	this->accountNum = accountNum;
	this->checkingBal = checkingBal;
	this->savingsBal = savingsBal;
}

void User::PrintUser() {
	std::cout << "\nName: " << this->name
			  << "\nEmail: " << this->email
			  << "\nAccount Number: " << this->accountNum
			  << "\nChecking Balance: $" << std::fixed << std::setprecision(2) << this->checkingBal
			  << "\nSavings Balance: $" << this->savingsBal << std::endl << std::endl;
}

std::string User::getEmail() {
	return this->email;
}

std::string User::getPassword() {
	return this->password;
}

double User::getCheckingBal() const {
	return this->checkingBal;
}

double User::getSavingsBal() const {
	return this->savingsBal;
}

void User::setCheckingBal(double checkingBal) {
	this->checkingBal = checkingBal;
}

void User::setSavingsBal(double savingsBal) {

	this->savingsBal = savingsBal;
}
