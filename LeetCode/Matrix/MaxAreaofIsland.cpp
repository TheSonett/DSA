// Q. https://leetcode.com/problems/max-area-of-island/
// 695. Max Area of Island

#include <iostream>
#include <vector>
#include <algorithm>

int solve(std::vector<std::vector<int>>& grid, int i, int j, int& row, int& col, int& count) {
	// if it is out of bounds or it has water, then return 0
	if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0) {
		return 0;
	}

	// make 1 to 0 once visited
	grid[i][j] = 0;

	// check the neighbours
	if (solve(grid, i - 1, j, row, col, count)) count++; // above
	if (solve(grid, i + 1, j, row, col, count)) count++; // bottom

	if (solve(grid, i, j - 1, row, col, count)) count++; // left
	if (solve(grid, i, j + 1, row, col, count)) count++; // right

	return 1;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
	int max = 0;
	int row = grid.size();
	int col = grid[0].size();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			int count = 1;
			if (grid[i][j] == 1) {
				solve(grid, i, j, row, col, count);
				max = std::max(max, count);
			}
		}
	}

	return max;
}

int main()
{
	std::vector<std::vector<int>> grid = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};

	std::cout << maxAreaOfIsland(grid); // output: 6
	std::cin.get();
}