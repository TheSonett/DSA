// Q. Write a program to find the leap year of the user given year

#include <iostream>

int main()
{
	int year;
	std::cout << "Enter a year: ";
	std::cin >> year;

	if (year % 400 == 0) {
		std::cout << year << " is a leap year" << std::endl;
	}
	else if (year % 100 == 0) {
		std::cout << year << " is not a leap year" << std::endl;
	}
	else if (year % 4 == 0) {
		std::cout << year << " is a leap year" << std::endl;
	}
	else {
		std::cout << year << " is not a leap year" << std::endl;
	}

	std::cin.get();
}