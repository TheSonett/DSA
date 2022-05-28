#include <iostream>
#include <unordered_map>

void frequency(int arr[], int size) {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, int>::iterator it;

    for(int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    for(it = freq.begin(); it != freq.end(); it++) {
        std::cout << "Element "<< it->first << " has " << it->second << " times." << std::endl;
    }
}


int main()
{
    int arr[] = {2, 3, 4, 2, 3, 4, 1, 2, 4, 3, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    frequency(arr, size);

    return 0;
}