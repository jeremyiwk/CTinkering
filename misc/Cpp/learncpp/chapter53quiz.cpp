#include <iostream>

bool isEven(int x)
{
	bool even {};
	even = !static_cast<bool>(x%2);
	return even;
}

int main()
{
	int x {};
	std::cout << "Enter a number:\n";
	std::cout << "x = ";
	std::cin >> x;
	if (isEven(x))
		std::cout << "x is even.\n"; 
	else if (!isEven(x))
		std::cout << "x is odd.\n";
	else
		std::cout << "Something weird happened.\n"; 
	return 0;
}