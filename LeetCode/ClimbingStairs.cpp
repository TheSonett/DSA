// Q. https://leetcode.com/problems/climbing-stairs/

#include <iostream>

int climbStairs(int n)
{
    long long one = 1;
    long long two = 1;

    long long steps = 0;

    for (int i = 1; i <= n; i++)
    {
        steps = one;
        one = one + two;
        two = steps;
    }

    return steps;
}

int main()
{
    int n = 20;

    std::cout << climbStairs(n);
    return 0;
}