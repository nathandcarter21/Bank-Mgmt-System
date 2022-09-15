#include <iostream>

#ifndef BANK_MGMT_SYSTEM_USER_H
#define BANK_MGMT_SYSTEM_USER_H


class User {
private:
	std::string name;
	std::string email;
	std::string password;
	int accountNum;
	double checkingBal;
	double savingsBal;

public:
	User(std::string name, std::string email, std::string password, int accountNum);

	User(std::string name, std::string email, std::string password, int accountNum, double checkingBal, double
	SavingsBal);

	void PrintUser();

	std::string getEmail();

	std::string getPassword();

	double getSavingsBal() const;

	double getCheckingBal() const;

	void setSavingsBal(double savingsBal);

	void setCheckingBal(double checkingBal);
};


#endif //BANK_MGMT_SYSTEM_USER_H
