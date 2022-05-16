// Array Implementation of Queue
// 1. Simple Queue
// 2. Circular Queue
// 3. Priority Queue
// 4. Double Ended Queue (DeQueue)

/*                     ------------------
    (Dequeue) front <-   10 34 58 72 89    <- rear (Enqueue)
                       ------------------
*/

#include <iostream>
#define SIZE 5

static int queue[SIZE];
static int rear = -1;
static int front = -1;

bool isFull() {
    if(rear == SIZE - 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if(front == -1 && rear == -1) {
        return true;
    }
    return false;
}

void Enqueue(const int& val) {
    if(isFull()) {
        std::cout << "ERROR: Queue is FULL!" << std::endl;
        return;
    } 
    else if(rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = val;
    }
    else {
        rear++;
        queue[rear] = val;
    }
}

void Dequeue() {
    if(isEmpty()) {
        printf("\n");
        std::cout << "ERROR: Queue is Empty!!" << std::endl;
    }
    else if(front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}


void displayQueue() {
    printf("\n");
    std::cout << "The queue values are: ";
    for(int i = front; i < rear + 1; i++) {
        std::cout << queue[i] << " ";
    }
}

int main()
{
    int val;
    char ch;
    bool isQuit = false;
    while(!isQuit) {
        std::cout << "Enter a value: ";
        std::cin >> val;

        Enqueue(val);
        displayQueue();

        printf("\n");
        std::cout << "Do you want to quit? (y/n): ";
        std::cin >> ch;

        (ch == 'y' || ch == 'Y') ? isQuit = true : isQuit = false;
    }

    std::cin.get();
}