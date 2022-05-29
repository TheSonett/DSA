// Write a program to check if a given number is palindrome or not 

#include <iostream>
#include <string>

bool isPalindromeNumber(int& value) {
	int temp = value;

	int rem, sum = 0;

	while (value > 0)
	{
		rem = value % 10;

		sum = (sum * 10) + rem;

		value /= 10;
	}

	if (temp == sum) {
		return true;
	} 
	else {
		return false;
	}
	
}

int main()
{
	int value = 121;
	if (isPalindromeNumber(value)) {
		std::cout << "It's a palindrome number";
	}
	else {
		std::cout << "It's not a palindrome number";
	}

	return 0;
}