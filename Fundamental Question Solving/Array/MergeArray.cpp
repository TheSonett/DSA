#include <iostream>
#include <algorithm>

int main() {
    int arr[6] = {2, 3, 4, 5, 6};
    int arr2[6] = {4, 8, 9, 1, 3};
    int arr3[10];

    std::merge(arr, arr + 5, arr2, arr2 + 5, arr3);

    for(int i = 0; i < 10; i++) {
        std::cout << arr3[i] << " ";
    }
    return 0;
}