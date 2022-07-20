#include <iostream>
#include <vector>

// TC -> O(n^2)
// SC -> O(n^2)

int gridTraveller(int& row, int& col) {
    std::vector<std::vector<int>> grid(row + 1, std::vector<int>(col + 1, 0));
    grid[1][1] = 1;

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if(j + 1 <= col) {
                grid[i][j+1] += grid[i][j];
            }   

            if(i + 1 <= row) {
                grid[i+1][j] += grid[i][j];
            }
        }
    }

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        printf("\n");
    }

    return grid[row][col];
}


int main()
{
    int row = 3;
    int col = 3;
    
    std::cout << gridTraveller(row, col) << std::endl;
    return 0;
}