// 31.	WAP to print Prime numbers in a given range + 20. WAP to identify an user given number is Prime number or not

#include <iostream>

bool isPrime(int val) {
	for (int i = 2; i * i <= val; i++) {
		if (val % i == 0) {
			return false;
		}
	}
	return true;
}


int main()
{
	int first, last;
	int i, j;

	std::cout << "From: ";
	std::cin >> first;

	std::cout << "To: ";
	std::cin >> last;

	std::cout << "The prime numbers are: " << std::endl;
	for (i = first; i <= last; i++) {
		for (j = 2; j <= i; j++) {
			if (i % j == 0) {
				break;
			}
		}

		if (i == j && i > 1) {
			std::cout << i << " ";
		}
	}

	printf("\n\n");
	for (int i = first; i <= last; i++) {
		if (isPrime(i)) {
			std::cout << i << " ";
		}
	}

	std::cin.get();
}