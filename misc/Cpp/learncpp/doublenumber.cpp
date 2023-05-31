#include <iostream>

int doubleNumber(int x)
{
	return 2*x;
}

int main()
{
	int input{};
	std::cin >> input;
	std::cout << doubleNumber(input);
	return 0;
}