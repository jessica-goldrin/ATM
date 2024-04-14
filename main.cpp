#include <stdlib.h>
#include <iostream>
#include <map>

// function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

// global variables
std::map<std::string, std::string> logins; // make value be <password, balance>

// global constants
const int EXIT = 0;
const int OPTION1 = 1;
const int OPTION2 = 2;
const int OPTION3 = 3;
const int OPTION4 = 4;
const int OPTION5 = 5;

// the main function
int main()
{
	std::cout << "Hi! Welcome to Jess' ATM Machine!" << std::endl;

	start();

	return 0;
}

void printIntroMenu()
{
	std::cout << "1 -> Login" << std::endl;
	std::cout << "2 -> Create Account" << std::endl;
	std::cout << "3 -> Quit" << std::endl;
}

void printMainMenu()
{
	std::cout << "1 -> Deposit Money" << std::endl;
	std::cout << "2 -> Withdraw Money" << std::endl;
	std::cout << "3 -> Request Balance" << std::endl;
	std::cout << "4 -> Log out" << std::endl;
	std::cout << "5 -> Quit" << std::endl;
}

void start()
{
	int option;
	bool continueLoop = true;

	while (continueLoop)
	{
		std::cout << "Please select an option from the menu below." << std::endl;
		printIntroMenu();

		std::cin >> option;

		switch (option)
		{
		case OPTION1:
			login();
			continueLoop = false;
			break;
		case OPTION2:
			createAccount();
			continue;
		case OPTION3:
			exit(EXIT);
		default:
			std::cout << "Invalid option, try again." << std::endl;
		}
	}
}

void createAccount()
{
	std::cout << "Please create a username." << std::endl;
	std::string username;
	std::cin >> username;

	std::cout << "Please create a password that meets the following criteria:" << std::endl;
	std::cout << "1. Be at least 8 characters long." << std::endl;
	std::cout << "2. Have at least 1 uppercase character." << std::endl;
	std::cout << "3. Have at least 1 lowercase character." << std::endl;
	std::cout << "4. Have at least 1 number." << std::endl;
	std::cout << "5. Have at least 1 symbol." << std::endl;

	std::string password;

	std::cin >> password;

	/*int len = password.length();
	for (int i = 0; i < len; ++i) {

	}*/

	logins[username] = password;

	std::cout << "Thank you! Your account has been created." << std::endl;
}

void login()
{
	int option;
	bool continueLoop = true;
	std::string username;
	std::string password;

	while (true)
	{
		std::cout << "Please enter your username." << std::endl;
		std::cin >> username;
		std::cout << "Please enter your password." << std::endl;
		std::cin >> password;

		if (logins.count(username) == 0 || logins[username] != password)
		{
			std::cout << "Invalid username or password. Try again." << std::endl;
			continue;
		}
		else
		{
			std::cout << "Access granted!" << std::endl;
			break;
		}
	}

	while (continueLoop)
	{
		std::cout << "Please choose from one of the following options." << std::endl;
		printMainMenu();
		std::cin >> option;

		/*switch (option) {
			case OPTION1:

		}*/
	}
}
