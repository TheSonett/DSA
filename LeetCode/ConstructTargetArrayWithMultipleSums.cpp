// Q. https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <iostream>
#include <vector>
#include <queue>

bool isPossible(std::vector<int> &target)
{
    std::priority_queue<int> pq;
    unsigned int sum = 0;

    for (int num : target)
        sum += num, pq.push(num);

    while (pq.top() != 1)
    {
        int num = pq.top();
        pq.pop();
        sum -= num;

        if (num <= sum || sum < 1)
            return false;

        num %= sum; 
        sum += num;
        pq.push(num ? num : sum);
    }
    return true;
}

int main()
{
    //std::vector<int> target {9,3,5};
    std::vector<int> target {1,1,1,2};

    std::cout << isPossible(target);
    return 0;
}