// Q. https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// Maximum sum sub-array of size K
// Important Notes: *std::max_element() & *std::min_element()


#include <iostream>
#include <vector>
#include <algorithm>

long maximumSumSubarray(int K, std::vector<int> &Arr , int N) {
    std::vector<long> maxSum{};
    long long sum = 0;

    int i = 0;
    int j = 0;

    while(j < Arr.size()) {
        sum += Arr[j];

        if((j - i + 1) < K) {
            j++;
        } 
        else if ((j - i + 1) == K) {
            maxSum.push_back(sum);
            sum -= Arr[i];
            i++;
            j++;
        }
    }

    return *(std::max_element(maxSum.begin(), maxSum.end()));
}


int main()
{
    std::vector<int> Arr {100, 200, 300, 400};
    int K = 2;
    int N = 4;

    std::cout << maximumSumSubarray(K, Arr, N);
    return 0;
}