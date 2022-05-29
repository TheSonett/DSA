// Write a program to check if a given string is palindrome or not 


#include <iostream>
#include <string>


std::string isPalindromeString(std::string myst) {
	for (int i = 0; i < myst.length() / 2; i++) {
		if (myst[i] == myst[myst.length() - i - 1]) {
			return "Yes";
		}
	}
	return "No";
}

bool isPalindrome(std::string mbstring) {
    if (mbstring == std::string(mbstring.rbegin(), mbstring.rend())) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
	std::string mbstring;
	std::cout << "Enter a string: ";
	std::cin >> mbstring;

	std::cout << isPalindromeString(mbstring);

    // if(isPalindrome(mbstring)) {
    //     std::cout << "It is a palindrome string" << std::endl;
    // }
    // else {
    //     std::cout << "It is not a palindrome string" << std::endl;
    // }

    return 0;
}