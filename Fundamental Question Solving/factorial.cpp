// Write a program to find factorial of a number;

#include <iostream>

// using recursion
int factorial(int value) {
	if (value == 0 || value == 1) {
		return 1;
	}
	else {
		return value * factorial(value - 1);
	}
}

// using loop
int fact(int value) {
	int fact = 1;
	for (int i = 1; i <= value; i++) {
		fact = fact * i;
	}

	return fact;
}

int main()
{
	int value;
	std::cout << "Enter a number: ";
	std::cin >> value;

	std::cout << "The factorial of " << value << " is: " << fact(value) << std::endl;
	//std::cout << "The factorial of " << value << " is: " << factorial(value) << std::endl;
	std::cin.get();
}