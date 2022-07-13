// Q. https://leetcode.com/problems/furthest-building-you-can-reach/

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int furthestBuilding(std::vector<int> &heights, int bricks, int ladders)
    {
        int heightSum = 0;
        int i = 0;

        std::priority_queue<int> maxHeap;

        for (i = 0; i < heights.size() - 1; i++)
        {
            if (heights[i] >= heights[i + 1])
            {
                continue;
            }
            else if (heights[i] < heights[i + 1])
            {
                heightSum += heights[i + 1] - heights[i];
                maxHeap.push(heights[i + 1] - heights[i]);

                while (heightSum > bricks && ladders > 0)
                {
                    ladders--;

                    heightSum -= maxHeap.top();
                    maxHeap.pop();
                }

                if(heightSum > bricks && ladders == 0) {
                    break;
                }

            }
        }

        return i;
    }
};


int main()
{
    Solution obj;
    std::vector<int> heights{4,2,7,6,9,14,12};

    int bricks = 5;
    int ladders = 1;

    std::cout << obj.furthestBuilding(heights, bricks, ladders);

    return 0;
}