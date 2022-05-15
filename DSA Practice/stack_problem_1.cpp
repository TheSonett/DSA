// Question 1: Write a program to implement a stack in an array stack_arr[] using stack_arr[0] as the top element.
// without Top pointer we can write push function something like this.

#include <iostream>
#define SIZE 3

static int stack_arr[SIZE];
static int first = -1;

void push(const int& data) {
	int i;
	first += 1;
	for (i = first; i > 0; i--) {
		stack_arr[i] = stack_arr[i - 1];
	}
	stack_arr[0] = data;
}

void printData() {
	std::cout << "Stack elements are: ";
	for (int i = 0; i < SIZE; i++) {
		std::cout << stack_arr[i] << " "; 
	}
}

int main()
{
	push(2);
	push(3);
	push(4);
	printData();
	std::cin.get();
}