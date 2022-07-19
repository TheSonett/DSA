#include <iostream>
#include <vector>
#include <cstring>

#define N 100

static int fibonacci[N];

// Tabulation Approach
// TC -> O(n)
// SC -> O(n)

int fib(int& index) {
    fibonacci[1] = 1;

    for (int i = 0; i < N; i++)
    {
        fibonacci[i + 1] += fibonacci[i];
        fibonacci[i + 2] += fibonacci[i];
    }

    return fibonacci[index];    
}


int main()
{
    memset(fibonacci, 0, sizeof(fibonacci));
    int index = 50;
    std::cout << fib(index) << std::endl;

    return 0;
}