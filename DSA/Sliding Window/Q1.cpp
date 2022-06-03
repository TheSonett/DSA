// Q1. WAP to find the maximum sum sub-array of size K
// Important Notes: *std::max_element() & *std::min_element()


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> vec = {0};

    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    int sum = 0;

    int i = 0;
    int j = 0;

    while(j < size) {
        sum += arr[j];

        if(j - i + 1 < k) {
            j++;
        } else if (j - i + 1 == k) {
            std::cout << sum << " ";
            vec.push_back(sum);

            sum -= arr[i];
            i++;
            j++;
        }
    }

    std::cout << "\nMax sum between those sub-arrays is: " << *(std::max_element(vec.begin(), vec.end())) << std::endl;
    return 0;
}