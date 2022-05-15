// Write a program to print the fibonacci series & write a fibonacci function

#include <iostream>
#include <array>

int fibonnaciFunction(int value) {
	if (value <= 1) {
		return value;
	}

	return fibonnaciFunction(value - 1) + fibonnaciFunction(value - 2);
}

void fibonnaciSeries(int value) {
	int a = 0, b = 1, c = 0;
	std::cout << "The series is: " << std::endl;
	for (int i = 0; i < value; i++) {
		std::cout << a << " ";
		c = a + b;
		a = b;
		b = c;
	}
}

int main()
{
	int value;
	std::cout << "Enter a value: ";
	std::cin >> value;

	std::cout << "The result is: " << fibonnaciFunction(value) << std::endl;
	//fibonnaciSeries(value);
	for (int i = 0; i < value; i++) {
		std::cout << fibonnaciFunction(i) << " ";
	}
	std::cin.get();
}