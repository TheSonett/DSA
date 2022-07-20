// Q. https://leetcode.com/problems/triangle/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int i, int j, std::vector<std::vector<int>>& triangle, std::vector<std::vector<int>>& temp) {
        // if we can at last index, then just return it
        if(i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if(temp[i][j] != -1) {
            return temp[i][j];
        }

        int bottom_left = triangle[i][j] + solve(i + 1, j, triangle, temp);
        int bottom_right = triangle[i][j] + solve(i + 1, j + 1, triangle, temp);
        
        temp[i][j] = std::min(bottom_left, bottom_right);
        return temp[i][j];
    }

    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        std::vector<std::vector<int>> temp (triangle.size(), std::vector<int>(triangle.size(), -1));
        return solve(0, 0, triangle, temp);
    }
};


int main()
{
    Solution sol;
    std::vector<std::vector<int>> triangle {
          {2},
         {3,4},
        {6,5,7},
       {4,1,8,3}
    };

    std::cout << sol.minimumTotal(triangle);
    return 0;
}