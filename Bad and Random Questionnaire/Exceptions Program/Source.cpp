#include <iostream>
#include <string>

int stringHolder;


// TODO: AFter creating two exceptions, you may research Thundercat's setup.  3 videos max.

int main() {
	std::cout << "Please give me your name" << std::endl;
	std::cin >> stringHolder;

	int addition;
	addition = 2 + stringHolder;
	std::cout << "The answer is: " << addition;
}