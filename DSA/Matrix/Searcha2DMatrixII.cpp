#include <iostream>
#include <vector>

// Brute Force Approach
// TC -> O(n^2)
// SC -> O(1)

// bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
//     int row = matrix.size();
//     int col = matrix[0].size();
//     bool ans = false;
//     for(int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++)
//         {
//             if(matrix[i][j] == target) {
//                 ans = true;
//                 break;
//             }
//         }
//         if(ans == true) {
//             break;
//         }
//     }
//     return ans;
// }


// TC -> O(row + col)
// SC -> O(1)
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int i = 0;
    int j = matrix[0].size() - 1;

    int row = matrix.size();
    int col = matrix[0].size();

    while ((i >= 0 && i < row) && (j >= 0 && j < col)) {
        if(matrix[i][j] == target) {
            return true;
        }
        else if(matrix[i][j] > target) {
            j--;
        }
        else if(matrix[i][j] < target) {
            i++;
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target = 5;

    if(searchMatrix(matrix, target)) {
        std::cout << "true\n";
    }
    else {
        std::cout << "false\n";
    }

    return 0;
}