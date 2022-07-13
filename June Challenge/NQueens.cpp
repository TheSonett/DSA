// Q. https://leetcode.com/problems/n-queens/

// #include <iostream>
// #include <vector>
// #include <string>

// std::vector<std::vector<std::string>> result{};
// bool isSafe(std::vector<std::string>& board, int row, int col) {
//     // vertical check
//     for (int i = 0; i < row; i++)
//     {
//         if(board[i][col] == 'Q') {
//             return false;
//         }
//     }

//     // diagonal left check
//     int maxLeft = std::min(row, col);
//     for (size_t i = 0; i <= maxLeft; i++)
//     {
//         if(board[row-i][col-i] == 'Q') {
//             return false;
//         }
//     }
    
    
//     // diagonal right check
//     int numOfRightElements = (std::size(board) - col - 1);
//     int maxRight = std::min(row, numOfRightElements);

//     for (size_t i = 0; i <= maxRight; i++)
//     {
//         if(board[row-i][col+i] == 'Q') {
//             return false;
//         }
//     }

//     return true;
// }

// int queens(std::vector<std::string>& board, int row) {
//     // if we reach to the last row, then we just display the board
//     if(row == std::size(board)) {
//         result.push_back(board);
//         return 1;
//     }
    
//     int count = 0;
//     // Now trying placing a queen on each column for a given row.
//     // Explore next row by placing Q at each valid column for the current row
//     for (int col = 0; col < std::size(board[0]); col++)
//     {
//         // place the queen if it is safe to place a queen
//         if(isSafe(board, row, col)) {
//             board[row][col] = 'Q';

//             // check below for rest of it & store backtracking count
//             count += queens(board, row + 1);

//             board[row][col] = 'X';
//         }
//     }

//     return count;
// }


// std::vector<std::vector<std::string>> solveNQueens(int n) {
//     std::vector<std::string> board(n, std::string(n, 'X'));
// 	std::cout << "Recursion count: " << queens(board, 0) << std::endl;
//     return result;
// }

// int main()
// {
//     std::vector<std::vector<std::string>> temp = solveNQueens(5);
//     std::cout << std::endl;
//     for (int i = 0; i < temp.size(); i++)
//     {
//         for (int j = 0; j < temp[i].size(); j++)
//         {
//             std::cout << temp[i][j] << " \n";
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
    
//     return 0;
// }

// Second Way
// Q. https://leetcode.com/problems/n-queens/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

static std::vector<std::vector<std::string>> result{};

bool isSafe(std::vector<std::string>& board, int row, int col) {
    // vertical check
    for (int i = 0; i < std::size(board); i++)
    {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // diagonal left check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q') {
            return false;
        }
    }


    // diagonal right check
    for (int i = row - 1, j = col + 1; i >= 0 && j < std::size(board[0]); i--, j++)
    {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

int queens(std::vector<std::string>& board, int row) {
    if (board.size() == 0) {
        return 1;
    }

    // if we reach to the last row, then we just display the board
    if (row == std::size(board)) {
        result.push_back(board);
        return 1;
    }

    int count = 0;
    // Now trying placing a queen on each column for a given row.
    // Explore next row by placing Q at each valid column for the current row
    for (int col = 0; col < std::size(board[0]); col++)
    {
        // place the queen if it is safe to place a queen
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';

            // check below for rest of it & store backtracking count
            count += queens(board, row + 1);

            board[row][col] = 'X';
        }
    }

    return count;
}


std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, 'X'));
    std::cout << queens(board, 0) << std::endl;
    return result;
}

int main()
{
    std::vector<std::vector<std::string>> temp = solveNQueens(4);
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
            std::cout << temp[i][j] << " \n";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}