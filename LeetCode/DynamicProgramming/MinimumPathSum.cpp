#include <iostream>
#include <vector>
#include <algorithm>


// TC -> O(N)
// SC -> O(N)
int helper(std::vector<std::vector<int>> &grid, int i, int j, std::vector<std::vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }

    if (i < 0 || j < 0)
    {
        return 1e9;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = grid[i][j] + helper(grid, i - 1, j, dp);
    int left = grid[i][j] + helper(grid, i, j - 1, dp);

    dp[i][j] = std::min(up, left);
    return dp[i][j];
}

int minPathSum(std::vector<std::vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    std::vector<std::vector<int>> dp(row, std::vector<int>(col, -1));

    return helper(grid, row - 1, col - 1, dp);
}

// TC -> O(N)
// SC -> O(1)
int minPathSum2(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 1; i < n; i++)
    {
        grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < m; i++)
    {
        grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[n - 1][m - 1];
}

int main()
{
    std::vector<std::vector<int>> grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    std::cout << minPathSum(grid);
    return 0;
}