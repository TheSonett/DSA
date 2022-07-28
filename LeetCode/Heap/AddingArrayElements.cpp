// Q. https://practice.geeksforgeeks.org/problems/adding-array-element4756/1

#include <iostream>
#include <algorithm>
#include <queue>

int minOperations(int arr[], int n, int k) {
    int ans = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for(int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
    }

    while (minHeap.top() < k) {
        int sumOfTwoElements = 0;
        for(int i = 1; i <=2; i++) {
            sumOfTwoElements += minHeap.top();
            minHeap.pop();
        }

        minHeap.push(sumOfTwoElements);
        ans++;
    }

    return ans;
}


int main() {
    int arr[] = {1, 10, 12, 9, 2, 3};
    int k = 6;
    int n = sizeof(arr)/ sizeof(arr[0]);

    std::cout << minOperations(arr, n, k);
    return 0;
}