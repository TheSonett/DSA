// Q. https://leetcode.com/problems/unique-paths/


// Constraints: 1 <= m, n <= 100
// Mistake: I didn't saw the constraints. so for cache[100][100] gave me runtime errors.

// Note: Always check constraints before setting any constant value.


#include <iostream>
#include <vector>

// m -> row
// n - column

long int cache[101][101];

int uniquePaths(int m, int n) {
     if(m == 0 && n == 0) {
        return 0;
    }

    if(m == 0 || n == 0) {
        return 0;
    }

    if(m == 1 && n == 1) {
        return 1;
    }

    if(cache[m][n] != 0) {
        return cache[m][n];
    }

    // down approach -> row--
    // right approach -> col--
   cache[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
   return cache[m][n];
}

int main() {
    std::cout << uniquePaths(3, 7) << "\n";
    std::cout << uniquePaths(23, 12) << "\n"; // Time Limit Exceeded

    return 0;
}