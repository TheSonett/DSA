// Q. https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <iostream>
#include <vector>

int solve(std::vector<int>& weight, std::vector<int>& value, int item, int capacity, std::vector<std::vector<int>>& dp) {
    // Base condition
    if(item == 0) {
        if(weight[item] <= capacity) {
            return value[item];
        }
        else {
            return 0;
        }
    }
    
    if(dp[item][capacity] != -1) {
        return  dp[item][capacity];
    }
    
    int include = 0;
    if(weight[item] <= capacity) {
        include = value[item] + solve(weight, value, item-1, capacity - weight[item], dp);
    }
    
    int exclude = solve(weight, value, item-1, capacity, dp);
    
    dp[item][capacity] = std::max(include, exclude);
    return dp[item][capacity];
}

int knapsack(std::vector<int> weight, std::vector<int> value, int n, int maxWeight) 
{
    std::vector<std::vector<int>> dp(n, std::vector<int>(maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
}

int main()
{
    std::vector<int> weight {1, 2, 4, 5};
    std::vector<int> value {5, 4, 8, 6};

    int items = 4;
    int maxWeight = 5;

    std::cout << knapsack(weight, value, 4, 5);
    return 0;
}