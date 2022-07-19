// Q. https://leetcode.com/problems/pascals-triangle/
// 118. Pascal's Triangle

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans(numRows);

    for (int i = 0; i < numRows; i++) {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
  
        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}

std::vector<std::vector<int>> generate2(int numRows) {
    std::vector<std::vector<int>> ans;

    for(int i = 0; i < numRows; ++i)
    {
        std::vector<int> row(i+1, 1);
        for(int j = 1; j < i; j++) {
            row[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        ans.push_back(row);
    }
    return ans;
}



int main()
{
    int numRows = 5;
    std::vector<std::vector<int>> answers = generate2(numRows);

    for(int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < answers[i].size(); j++) {
            std::cout << answers[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}