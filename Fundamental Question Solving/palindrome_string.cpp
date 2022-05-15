// Write a program to check if a given string is palindrome or not 

#include <iostream>
#include <string>

std::string isPalindromeString(std::string mystr) {
	// Iterate over the range [0, N/2]
	for (int i = 0; i < mystr.length() / 2; i++) {
		if (mystr[i] != mystr[mystr.length() - i - 1]) {
			return "No";
		}
	}
	return "Yes";
}

bool isPalindromeNumber(int& value) {
	int temp = value;
	int rem, sum = 0;

	while (value > 0)
	{
		rem = value % 10;
		std::cout << "rem: " << rem << std::endl;
		sum = (sum * 10) + rem;
		std::cout << "sum: " << sum << std::endl;
		value /= 10;
		std::cout << "value: " << value << std::endl;
		std::cout << "-----------" << std::endl;
	}

	if (temp == sum) {
		return true;
	}
	
	return false;
}

int main()
{
	/*std::string mystring;
	std::cout << "Enter a string: ";
	std::cin >> mystring;

	if (mystring == std::string(mystring.rbegin(), mystring.rend())) {
		std::cout << "It is a palindrome string" << std::endl;
	}
	else {
		std::cout << "It is not a palindrome string" << std::endl;
	}

	std::cout << isPalindromeString(mystring);*/

	int value = 121;
	if (isPalindromeNumber(value)) {
		std::cout << "It's a palindrome number";
	}
	else {
		std::cout << "It's not a palindrome number";
	}

	std::cin.get();
}