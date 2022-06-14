#include <iostream>
#include <algorithm>
#include <array>

#define N 100

class Heap {
    private:
        int arr[N];
        int size;
    public:
        Heap() {
            arr[0] = -1;
            size = 0;
        }
    public:
        // insertion -> O(logn) time complexity
        void insert(int value) {
            // adding element at end, first will index at index 1
            size = size + 1;
            int index = size;
            arr[index] = value;

            // make it balance
            while (index > 1)
            {
                int parent = index / 2;
                if(arr[parent] < arr[index]) {
                    std::swap(arr[parent], arr[index]);
                    index = parent;
                }
                else {
                    return;
                }
            }
        }
        // deletion
        void deleteFromHeap() {
            if(size == 0) {
                std::cout << "Nothing to delete here!\n";
                return;
            }

            // step1: delete element from last
            // first, take out the element from last, then put it in first & then decrement it's size to delete
            arr[1] = arr[size];
            size--;

            int index = 1;
            while (index < size)
            {
                int leftIndex = 2 * index;
                int rightIndex = 2 * index + 1;
                int nextIndex = index;

                if(leftIndex < size && arr[nextIndex] < arr[leftIndex]) {
                    nextIndex = leftIndex;
                }
                else if(rightIndex < size && arr[nextIndex] < arr[rightIndex]) {
                    nextIndex = rightIndex;
                }

                if(nextIndex == index) {
                    break;
                }
                else {
                    std::swap(arr[index], arr[nextIndex]);
                    index = nextIndex;
                }
            }
        }

        // Max heapify
        void Heapify(int arr[], int size, int index) {
            int element = index;
            int leftElement = 2 * index;
            int rightElement = 2 * index + 1;

            if(leftElement <= size && arr[element] < arr[leftElement]) {
                element = leftElement;
            }

            if(rightElement <= size && arr[element] < arr[rightElement]) {
                element = rightElement;
            }

            if(element != index) {
                std::swap(arr[element], arr[index]);
                Heapify(arr, size, element);
            }
        }

        // Min heapify
        // void Heapify(std::array<int, 6>& arr, int size, int index) {
        //     int element = index;
        //     int leftElement = 2 * index + 1;
        //     int rightElement = 2 * index + 2;

        //     if(leftElement <= size && arr[element] > arr[leftElement]) {
        //         element = leftElement;
        //     }

        //     if(rightElement <= size && arr[element] > arr[rightElement]) {
        //         element = rightElement;
        //     }

        //     if(element != index) {
        //         std::swap(arr[element], arr[index]);
        //         Heapify(arr, arr.size(), element);
        //     }
        // }

        void heapSort(int arr[], int size) {
            int t = size;

            while (t > 1)
            {
                std::swap(arr[t], arr[1]);
                t--;

                Heapify(arr, t, 1);
            }
        }
        
        // display
        void print() {
            for (int i = 1; i <= size; i++)
            {
                std::cout << arr[i] << " ";
            }
        }
};

int main()
{
    Heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);

    // h.print();
    // printf("\n");
    // h.deleteFromHeap();
    // h.print();

    int array[N] = {54, 53, 55, 52, 50};
    int n = 5;

    std::cout << std::endl;
    for (int i = n/2; i > 0; i--)
    {
        h.Heapify(array, n, i);
    }

    std::cout << "\n\nAfter Heapify....\n";

    for (int i = 1; i <= n; i++)
    {
        std::cout << array[i] << " ";
    } 
    std::cout << std::endl;

    // heapSort
    h.heapSort(array, n);
    std::cout << "\n\nAfter Heap Sort....\n";

    for (int i = 1; i <= n; i++)
    {
        std::cout << array[i] << " ";
    } 
    std::cout << std::endl;

    return 0;
}