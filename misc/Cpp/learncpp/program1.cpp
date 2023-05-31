#include <iostream>

int main() 
{
	std::cout << "Enter two integers: ";

	int num1 {};
	std::cin >> num1;

	int num2 {};
	std::cin >> num2;

	std::cout << num1  << " + " << num2 << " = " << num1 + num2 << '\n';

	std::cout << num1  << " - " << num2 << " = " << num1 - num2 << '\n';

	return 0;
}