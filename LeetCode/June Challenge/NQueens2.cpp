// Q. https://leetcode.com/problems/n-queens-ii/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<std::vector<std::string>> result{};

void display() {
    std::cout << std::endl;

    for (int i = 0; i < std::size(result); i++)
    {
        for (int j = 0; j < std::size(result[0]); j++)
        {
            std::cout << result[i][j] << "\n";
        }
        std::cout << std::endl;
    }
}

bool isSafe(std::vector<std::string>& board , int row, int col)
{
    // vertical row check
    for (int i = 0; i < board.size(); i++)
    {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    // horizontal column check
    for (int i = 0; i < board[0].size(); i++)
    {
        if(board[row][i] == 'Q') {
            return false;
        }
    }

    // diagonal left check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    // diagonal right check
    for (int i = row - 1, j = col + 1; i >= 0 && j < std::size(board[0]); i--, j++)
    {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

int solve(std::vector<std::string>& board, int row) 
{
    // check if board is empty
    if(board.size() == 0) {
        return 1;
    }

    // check if we reached to the last row
    if(row == std::size(board)) {
        result.push_back(board);
        return 1;
    }

    int count = 0;
    // So, now we are trying to put a queen on each column for a given row
    for (int col = 0; col < std::size(board[0]); col++)
    {
        // check if that place is safe to put a queen or not
        if(isSafe(board, row, col)) {
            board[row][col] = 'Q';
            count += solve(board, row + 1);
            board[row][col] = 'X';
        }
    }

    return count;
}

int totalNQueens(int n) 
{
    std::vector<std::string> board(n, std::string(n, 'X'));
    return solve(board, 0);
}

int main()
{
    int n = 5;
    std::cout << totalNQueens(n);

    display();
    return 0;
}