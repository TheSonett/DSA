// June Challenge - Day2
// Q. https://leetcode.com/problems/transpose-matrix/


#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int matrix_size = matrix.size();
        int element_size = matrix[0].size();

        std::vector<std::vector<int>> result(element_size, std::vector<int>(matrix_size, 0));

        for (int col = 0; col < matrix_size; col++)
        {
            for (int row = 0; row < element_size; row++)
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
         {2, 4, -1},
         {-10, 5, 11},
         {18, -7, 6}
        // {1, 2, 3},
        // {4, 5, 6}
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