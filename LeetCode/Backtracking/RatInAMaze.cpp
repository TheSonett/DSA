// Q. https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030/
// Q. https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

bool isSafe(int x, int y, std::vector<std::vector<int>>& arr, std::vector<std::vector<bool>>& visited, int& n) {
    if( (x >= 0 && x < n) &&  (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1 ) {
            return true;
    }
    else {
        return false;
    }
}

void solve(int x, int y, std::vector<std::vector<int>>& arr, std::vector<std::vector<bool>>& visited, std::string path, std::vector<std::string>& ans, int n) {
    // base case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    // 4 movements
    visited[x][y] = 1;

    // Up
    if(isSafe(x-1, y, arr, visited, n)) {
        solve(x-1, y, arr, visited, path + 'U', ans, n);
    }
    // Down
    if(isSafe(x+1, y, arr, visited, n)) {
        solve(x+1, y, arr, visited, path + 'D', ans, n);
    }
    // Right
    if(isSafe(x, y+1, arr, visited, n)) {
        solve(x, y+1, arr, visited, path + 'R', ans, n);
    }
    // left
    if(isSafe(x, y-1, arr, visited, n)) {
        solve(x, y-1, arr, visited, path + 'L', ans, n);
    }

    visited[x][y] = 0;
    return;
}


std::vector<std::string> searchMaze(std::vector<std::vector<int>>& arr, int n) {
    std::vector<std::string> ans;
    std::vector<std::vector<bool>> visited (n, std::vector<bool>(n, 0));
    std::string path = "";

    if(arr[0][0] == 0) {
        return ans;
    }

    solve(0, 0, arr, visited, path, ans, n);
    return ans;
}

int main() {
    std::vector<std::vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = arr.size();
    std::vector<std::string> ans = searchMaze(arr, n);
    for(auto i : ans) {
        std::cout << i << std::endl;
    }

    return 0;
}