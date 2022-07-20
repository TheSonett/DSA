// Q. https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// 1482. Minimum Number of Days to Make m Bouquets

#include <iostream>
#include <vector>
#include <algorithm>

int minDays(std::vector<int>& bloomDay, int m, int k) {
    // when each day comes, we can have one flower. So, in this case, we have 5 flowers
    // if m*k = total flower is greater than 5 flowers, Then it's not possible to make a bouquet.
    if(bloomDay.size() < m*k) {
        return -1;
    }

    int left = *std::min_element(bloomDay.begin(), bloomDay.end());
    int right = *std::max_element(bloomDay.begin(), bloomDay.end());

    int adjecentCount;
    int mid;
    int bouqueCount;

    while (left < right)
    {
        // get the mid element, which we will calculate in every iteration
        mid = left + (right - left) / 2;

        // the current and adj is 0
        bouqueCount = 0; adjecentCount = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // the flowers which didn't bloom yet
            if(bloomDay[i] > mid) {
                adjecentCount = 0;
            }
            // the flowers is bloomed
            else {
                adjecentCount++;
                // when we the adjCount is == number of flower in each bouquet, the we have created a bouquet
                if(adjecentCount == k) {
                    adjecentCount = 0;
                    bouqueCount++;
                }
            }

            // When we have all the flowers.
            if(bouqueCount >= m) {
                break;
            }
        }

        // update left & right pointers
        if(bouqueCount < m) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main()
{
    std::vector<int> bloomDay {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;
    std::cout << minDays(bloomDay, m, k);
    return 0;
}

