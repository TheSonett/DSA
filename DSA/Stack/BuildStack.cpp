// Array Implementation of Stacks
// Worst case: Push Operation O(n), 
//			   Pop Operation is O(1), 
//			   Peek Operation is O(1)

/*
*	|	50	 |
*	|	40	 |
*	|	30	 |
*	|	20	 |
*	|	10	 |
*	|________|
*	  stack
*/


#include <iostream>
#define SIZE 5  // [0][1][2][3][4]

static int stack[SIZE];
static int top = -1; // To indicate that the stack is empty, we will put -1 in the variable top

static int choice;
static char isContinue;
static int data;

bool isFull() {
	if (top == SIZE - 1) { // When top is pointing to the last element, it means the stack is full
		return true;
	}
	return false;
}

bool isEmpty() {
	if (top == -1) {
		return true;
	}
	return false;
}

void push(int& data) 
{
	if (isFull()) {
		std::cout << "		Wait! Stack Overflow! :(" << std::endl;
	}
	else {
		top++; // As it's initial value is -1, we have to increment the top value by 1 every-time when we push an element
		stack[top] = data;
		std::cout << " - Data Inserted Successfully! :) " << std::endl;
	}
}

void pop() {
	if (isEmpty()) {
		std::cout << "		Wait! Stack is empty! :| " << std::endl;
		return;
	}
	else {
		int value = 0;
		value = stack[top];
		top--;

		std::cout << " - Deleted Data is: " << value << std::endl;
	}
}

void TopElement() {
	if (top == -1) {
		std::cout << "		Wait! Stack is empty! :| " << std::endl;
		return;
	}
	else {
		std::cout << "The Top most element is: " << stack[top] << std::endl;
	}
}

void ShowElements() {
	if (isEmpty()) {
		std::cout << "There is nothing to show! :(" << std::endl;
	}
	else {
		std::cout << "Elements on stack are: ";
		for (int i = top; i >= 0; i--)
		{
			if (stack[i] != 0) {
				std::cout << stack[i] << " ";
			}
		}
	}
}

int main()
{
	do {
		system("cls");
		std::cout << " ::: Array Implementation of Stacks :::: " << std::endl;
		std::cout << "___________________________________________" << std::endl;

		printf("\n");
		std::cout << "1. Push Element" << std::endl;
		std::cout << "2. Pop Element" << std::endl;
		std::cout << "3. Top Element" << std::endl;
		std::cout << "4. Is stack empty?" << std::endl;
		std::cout << "5. Is stack full?" << std::endl;
		std::cout << "6. Show Elements" << std::endl;
		std::cout << "7. Exit" << std::endl;

		printf("\n");
		std::cout << "Enter your choice to perform operation: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			printf("\n");
			std::cout << " - Enter the element to push data into the stack: ";
			std::cin >> data;
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			TopElement();
			break;
		case 4:
			isEmpty() ? std::cout << "Yes! Stack is empty!!" << std::endl :
				std::cout << "No! Stack has some elements!!" << std::endl;
			break;
		case 5:
			isFull() ? std::cout << "Yes! Stack is full!!" << std::endl : 
				       std::cout << "No! Stack is not full yet!!" << std::endl;
			break;
		case 6:
			printf("\n");
			ShowElements();
			break;
		case 7:
			exit(0);
			break;
		default:
			printf("\n");
			std::cout << "	?? Invalid choice! Try Again ?? " << std::endl;
			break;
		}

		printf("\n\n");
		std::cout << "Do you want to continue? (y/n): " << std::endl;
		std::cin >> isContinue;

	} while (isContinue == 'y' || isContinue == 'Y');
	std::cin.get();
}