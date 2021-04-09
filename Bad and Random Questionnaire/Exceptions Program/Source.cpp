#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <cstdlib>


int stringHolder;

// TODO: AFter creating two exceptions, you may research Thundercat's setup.  3 videos max.

// Divide by zero
// Create account, password must be the same
// enter age, throw places player into a group
// favorite color throw if we have the same color

std::string userName;
std::string userCode;
int failedSignInAttempts = 0;

void CreateAccount();
void SignIn();
void EnterAge();
void SimonSaysMath();
void ErrorHandler(std::string error);

// Introduction to the program
void Introduction() {
	std::cout << "Welcome to the questionnaire" << std::endl;
	// This allows the user to call the thread that the program is running in.
	std::cout << std::this_thread::get_id() << std::endl;
	CreateAccount();
}

// Allows the player to create a new account with their chosen Username and Secret Code
void CreateAccount() {
	failedSignInAttempts = 0;
	std::cout << "Create an account!" << std::endl;
	std::cout << "Pleae enter a Username: ";
	std::cin >> userName;
	std::cout << std::endl;
	std::cout << "Welcome, " << userName << "! Please enter the one word secret code" << std::endl;
	std::cout << "you'll use the next time you sign in.\nSecret code: ";
	std::cin >> userCode;
	std::cout << "~   ~   ~  Thank you!  ~   ~   ~" << std::endl;
	std::cout << std::endl;
	SignIn();
}

// Makes the player sign into their account, ensuring that they remembered their password.
void SignIn() {
	std::string codeCheck;
	std::cout << "Please sign in." << std::endl;
	std::cout << "Account Name: " << userName << std::endl;
	std::cout << "Secret Code: ";
	std::cin >> codeCheck;
	// The program attempts to use the given code to sign in 
	try {
		// If the code matches the initally given code, the user is able to sign in
		if (codeCheck == userCode) {
			std::cout << "~  Sign in successful!  ~" << std::endl;
			EnterAge();
		}
		// If the secret code does not match, an error is thrown
		else {
			throw 45;
		}
	}
	// This catch handles the sign in error specifically
	catch (int errorCode){
		// The error code checker is counting how many times the player has failed to enter their password successfully
		// Upon three unsuccessful or failed sign in attempts the user is prompted to create a new account.
		if (failedSignInAttempts == 2) {
			std::cout << "You've failed to sign in too many times." << std::endl;
			std::cout << "Account terminated. Returning to main menu." << std::endl;
			Introduction();
		}
		// This is the error code that throws if the user didn't
		else {
			if (errorCode == 45) {
				std::cout << "That's not the code you created.  Please try again." << std::endl;
				failedSignInAttempts++;
				SignIn();
			}
		} 
	}
}

// This asks the user what age they are.
void EnterAge() {
	int userAge;
	std::cout << "How old are you?\nAge: " << std::endl;
	try {
		std::cin >> userAge;
		throw userAge;
	}
	catch (int ageBracket) {
		if (ageBracket > 99) {
			std::cout << "I see you are of the immortal kind." << std::endl;
		}
		else if (ageBracket >= 65 && ageBracket <= 98) {
			std::cout << "I am honored to host a service for one so wise." << std::endl;
		}
		else if (ageBracket >= 25 && ageBracket <= 64) {
			std::cout << "You are my targeted demographic, welcome." << std::endl;
		}
		else if (ageBracket >= 15 && ageBracket <= 24) {
			std::cout << "Welcome to my program!  We're in the same demographic!" << std::endl;
		}
		else if (ageBracket >= 0 && ageBracket <= 14) {
			std::cout << "I don't know how you got here but hi." << std::endl;
		}
		else {
			std::cout << "WHAT ARE YOU?!?" << std::endl;
			ErrorHandler("User is too old.");
		}
	}
}

void FavoriteColor() {
	int userColor;
	std::cout << "Choose your favorite color from the list." << std::endl;
	std::cout << "1\tRed" << std::endl;
	std::cout << "2\tOrange" << std::endl;
	std::cout << "3\tYellow" << std::endl;
	std::cout << "4\tGreen" << std::endl;
	std::cout << "5\tCyan" << std::endl;
	std::cout << "6\tBlue" << std::endl;
	std::cout << "7\tPurple" << std::endl;
	std::cout << "8\tBurgundy" << std::endl;
	std::cout << "9\tPink" << std::endl;
	std::cin >> userColor;
	if (userColor >= 1 && userColor <= 9) {
		if (userColor <= 4 && userColor >= 1) {
			std::cout << "What a wonderful color.  Moving on." << std::endl;
		}
		else if (userColor == 5) {
			std::cout << "We share the same favorite color! On to math." << std::endl;
		}
		else if (userColor >= 6 && userColor <= 9) {
			std::cout << "Lovely choice! Now for the algebraic portion." << std::endl;
		}
		SimonSaysMath();
	}
	else {
		ErrorHandler("Invalid number chosen.");
	}
}

// Divide by 0
void SimonSaysMath() {
	int num1 = rand() % 10 + 1;
	int num2 = rand() % 10 + 1;
	std::cout << "Time to play Simon Says!" << std::endl;
	std::cout << "Simon says, Add " << num1 << " + " << num2 << " = ?" << std::endl;
	int currentTotal = num1 + num2;
	int userTotal;
	std::cout << "Answer: ";
	try
	{
		std::cin >> userTotal;
		if (userTotal == currentTotal) {
			std::cout << "we didd it!" << std::endl;

		}
		if (userTotal != currentTotal) {
			std::cout << "wrong af" << std::endl;
			throw;
		}
	}
	catch (const std::exception&)
	{
		std::cout << "uh oh" << std::endl;
	}
	
}

// Handles errors from any part of the program.
void ErrorHandler(std::string error) {
	std::string ErrorPrint = error;

	if (error == "User is too old.") {
		std::cout << "Don't you have something more fun to be doing?" << std::endl;
		std::cout << "If your lengthy life has led you to this very" << std::endl;
		std::cout << "moment of playing my program then I welcome you " << std::endl;
		std::cout << "with open arms and an uneasy smile." << std::endl;
		FavoriteColor();

	}
	if (error == "Invalid number chosen.") {
		std::cout << "You didn't choose one of the specified numbers." << std::endl;
		std::cout << "Please choose one of the colors listed by entering" << std::endl;
		std::cout << "the correct number." << std::endl;
		FavoriteColor();
	}	
}

int main() {
	srand(time(NULL));
	SimonSaysMath();
}