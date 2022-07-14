// Q. https://leetcode.com/problems/min-stack/
// 155. Min Stack

/*
* Notes:
* 
* Time Complexity: O(1)
* Space Complexity: O(n^2)
* 
*/ 

#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;
public:
    MinStack() {}

    void push(int val) {
        stack.push(val);

        // fetching minimum value
        if (minStack.size() == 0 || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (stack.top() == minStack.top()) {
            stack.pop();
            minStack.pop();
        }
        else {
            stack.pop();
        }
    }

    int top() {
        if (stack.size() == 0) {
            return -1;
        }

        return stack.top();
    }

    int getMin() {
        if (minStack.size() == 0) {
            return -1;
        }

        return minStack.top();
    }
};