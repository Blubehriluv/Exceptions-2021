#include <iostream>
#include <string>
#include <limits>

int stringHolder;

// TODO: AFter creating two exceptions, you may research Thundercat's setup.  3 videos max.

// Divide by zero
// Create account, password must be the same
// enter age, throw places player into a group
// favorite color throw if we have the same color

std::string userName;
std::string userCode;

int main() {
	try
	{
		
	}
	catch (const std::exception&)
	{

	}
}

void Introduction() {
	std::cout << "Welcome to the questionnaire" << std::endl;
}

void CreateAccount() {

	std::cout << "Create an account!" << std::endl;
	std::cout << "Pleae enter a Username" << std::endl;
	std::cin >> userName;
	std::cout << "Welcome, " << userName << "! Please enter the one word secret code" << std::endl;
	std::cout << "you'll use the next time you sign in." << std::endl;
	std::cin >> userCode;
	std::cout << "Thank you!" << std::endl;

}

void SignIn() {
	std::string codeCheck;
	std::cout << "Please sign in." << std::endl;
	std::cout << "Account Name: " << userName << std::endl;
	std::cout << "Secret Code: ";
	std::cin >> codeCheck;
	try {
		if (codeCheck == userCode) {
			std::cout << "Sign in successful" << std::endl;
		}
		else {
			throw code_match_failed("");
		}
	}
	catch (exception& e){
	}
}

void EnterAge() {

}

void FavoriteColor() {

}

void SmartsTesting() {

}
