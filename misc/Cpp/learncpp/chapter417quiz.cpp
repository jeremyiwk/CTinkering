#include <string>
#include <iostream>

int main()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	int sum{};
	int letters{};
	letters = static_cast<int>(name.length());
	sum = letters+ age;
	std::cout << "The sum of your age and the characters in your name is: " << sum << '\n';

	return 0;
}