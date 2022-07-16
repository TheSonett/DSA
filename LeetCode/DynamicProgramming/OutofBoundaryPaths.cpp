// link : https://leetcode.com/problems/out-of-boundary-paths/
// 576. Out of Boundary Paths

#include <iostream>
#include <cstring>

int dp[51][51][51];
long long int mod = 1e9 + 7;

int solve(int i, int j, int m, int n, int moves) {
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return 1;
    }

    if(moves <= 0) {
        return 0;
    }

    if(dp[i][j][moves] != -1) {
        return dp[i][j][moves];
    }

    long long int temp = 0;

    temp += solve(i-1, j, m, n, moves-1); //up
    temp += solve(i+1, j, m, n, moves-1); //down
    temp += solve(i, j-1, m, n, moves-1); //left
    temp += solve(i, j+1, m, n, moves-1); //right

    dp[i][j][moves] = temp % mod;
    return dp[i][j][moves];
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(dp, -1, sizeof(dp));
    int ans = solve(startRow, startColumn, m, n, maxMove);
    return ans;
}


int main()
{
    std::cout << findPaths(2, 2, 2, 0, 0); // output: 6
    return 0;
}