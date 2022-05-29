// Write a program to print the fibonacci series & write a fibonacci function

#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>

static int fibonacciCache[50];

int fibonnaciFunction(int value) {
	if (value <= 1) {
		return value;
	}

	if(fibonacciCache[value] != 0) {
		return fibonacciCache[value];
	}

	long int nthFibonacciNumber = (fibonnaciFunction(value - 1) + fibonnaciFunction(value - 2));
	fibonacciCache[value] = nthFibonacciNumber;

	return nthFibonacciNumber;
}

void fibonnaciSeries(int value) {
	int a = 0, b = 1, c = 0;
	std::cout << "\nThe series is: " << std::endl;
	for (int i = 0; i < value; i++) {
		std::cout << a << " ";
		c = a + b;
		a = b;
		b = c;
	}
}



int fibonacciFormula(int value) {
	return std::pow((1 + std::sqrt(5) / 2), value);
}

int main()
{
	int value;
	std::cout << "Enter a value: ";
	std::cin >> value;

	// for(int i = 0; i < value; i++) {
	// 	std::cout << fibonnaciFunction(i) << " ";
	// }

	//fibonnaciSeries(value);

	
	std::cout << fibonacciFormula(value);
	std::cin.get();
}


// Formula: (1 + root 5 / 2) ^ n 