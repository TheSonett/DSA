// Q. https://practice.geeksforgeeks.org/contest/interview-series-60/problems/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> makeBeautiful(std::vector<int> arr) {
    std::stack<int> stack;

    for(int v : arr) {
        if(stack.size() == 0) {
            stack.push(v);
        }
        else {
            if(v >= 0 && stack.top() >= 0) {
                stack.push(v);
            }
            else if(v < 0 && stack.top() < 0) {
                stack.push(v);
            }
            else {
                stack.pop();
            }
        }
    }

    std::vector<int> ans;
    while(stack.size() > 0) {
        ans.push_back(stack.top());
        stack.pop();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    std::vector<int> arr {-3, -1, -19, 0, 6, -13 ,12};
    std::vector<int> ans = makeBeautiful(arr);

    for(auto i : ans) {
        std::cout << i << " ";
    }
    return 0;
}