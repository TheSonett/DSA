// Q. https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>

class NumMatrix
{
public:
    std::vector<std::vector<int>> sum{};
    NumMatrix(std::vector<std::vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Find column wise sum, put the value into the matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        // Find row wise sum, put the value into the matrix
        for (int i = 1; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] += matrix[i-1][j];
            }
        }


        sum = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int total = sum[row2][col2];
        int remainingSum = ((col1 != 0) ? sum[row2][col1 - 1] : 0) + ((row1 != 0) ? sum[row1 - 1][col2] : 0) 
                                        - ((row1 != 0 && col1 != 0) ? sum[row1-1][col1-1] : 0);
        
        return (total - remainingSum);
    }
};

int main()
{
    std::vector<std::vector<int>> matrix {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix* obj = new NumMatrix(matrix);
    //[2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]

    int param_1 = obj->sumRegion(2, 1, 4, 3);
    obj->sumRegion(1, 1, 2, 2);
    obj->sumRegion(1, 2, 2, 4);

    std::cout << param_1;

    return 0;
}