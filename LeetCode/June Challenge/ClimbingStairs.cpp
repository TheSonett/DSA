// Q. https://leetcode.com/problems/climbing-stairs/

#include <iostream>

int climbStairs(int n)
{
    long long currentStep = 0;
    long long nextStep = 1;

    long long totalSteps = 0;

    for (int i = 1; i <= n; i++)
    {
        totalSteps = currentStep + nextStep;
        currentStep = nextStep;
        nextStep = totalSteps;
    }

    return totalSteps;
}

// int climbStairs(int n)
// {
//     long long one = 1;
//     long long two = 1;

//     long long steps = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         steps = one;
//         one = one + two;
//         two = steps;
//     }

//     return steps;
// }

int main()
{
    int n = 2;

    std::cout << climbStairs(n);
    return 0;
}