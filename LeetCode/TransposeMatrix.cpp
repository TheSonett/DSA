// June Challenge - Day2
// Q. https://leetcode.com/problems/transpose-matrix/


#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int row_size = matrix.size(); // for 2x3, output is 2.
        int col_size = matrix[0].size(); // for 2x3, output is 3.

        std::vector<std::vector<int>> result(col_size, std::vector<int>(row_size)); // setting up the size of result matrix
        // Here, we're saying that, how many elements will form a 1D array? and how many set of col_size 1D array we'll gonna insert. and set of 1D array
        // means, a 1D vector, so we have to write std::vector<int>(row_size);

        for (int col = 0; col < row_size; col++)
        {
            for (int row = 0; row < col_size; row++)
            {
                result[row][col] = matrix[col][row];
            }
        }
        
        return result;
    }
};


int main()
{
    Solution sol;

    std::vector<std::vector<int>> matrix{
        //  {2, 4, -1},
        //  {-10, 5, 11},
        //  {18, -7, 6}

        // {0, 0, 0},
        // {0, 0, 0}

        // {0},
        // {0}

        // {0},

        {1, 2, 3},
        {4, 5, 6}
    };

    std::vector<std::vector<int>> result = sol.transpose(matrix);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}