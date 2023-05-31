#include "io.h"
#include <iostream>

int readNumber()
{
	int x {};
	std::cout << "Enter a number:\n";
	std::cin >> x;
	return x;
}

void writeAnswer(int x, int y)
{
	int z {};
	z = x+y;
	std::cout << "The sum of " << x << " and " << y << " is " << z << '\n';
}