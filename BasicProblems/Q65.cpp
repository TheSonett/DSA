// 65.	WAP to Remove duplicate elements in an array

#include <iostream>
#include <unordered_map>
#define N 5


// count the frequency
    // for (int i = 0; i < arr_size; i++) {
    //     numRay[numRay[i] % arr_size]
    //         = numRay[numRay[i] % arr_size] + arr_size;
    // }
    // cout << "The repeating elements are : " << endl;
    // for (int i = 0; i < arr_size; i++) {
    //     if (numRay[i] >= arr_size * 2) {
    //         cout << i << " " << endl;
    //     }
    // }


int main()
{
    int arr[N];
    std::cout << "Enter "<< N <<" elements in an array: " << std::endl;

    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(arr[i] == arr[j]) {
                arr[j] = -99999;
            }
        }
    }

    std::cout << "\nThe array values are: " << std::endl;
    for(int i = 0; i < N; i++) {
        if(arr[i] > -99999)
            std::cout << arr[i] << " ";
    }
    
    std::cin.get();
}