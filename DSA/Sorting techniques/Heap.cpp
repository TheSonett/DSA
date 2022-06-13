#include <iostream>
#include <algorithm>
#include <array>

#define N 100

class Heap {
    private:
        std::array<int, N> arr{};
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

        // heapify
        void MaxHeapify(std::array<int, 6>& arr, int size, int index) {
            int element = index;
            int leftElement = 2 * index;
            int rightElement = 2 * index + 1;

            if(leftElement < size && arr[element] < arr[leftElement]) {
                element = leftElement;
            }

            if(rightElement < size && arr[element] < arr[rightElement]) {
                element = rightElement;
            }

            if(element != index) {
                std::swap(arr[element], arr[index]);
                MaxHeapify(arr, arr.size(), element);
            }
        }

        void MinHeapify(std::array<int, 6>& arr, int size, int index) {
            int element = index;
            int leftElement = 2 * index + 1;
            int rightElement = 2 * index + 2;

            if(leftElement < size && arr[element] > arr[leftElement]) {
                element = leftElement;
            }

            if(rightElement < size && arr[element] > arr[rightElement]) {
                element = rightElement;
            }

            if(element != index) {
                std::swap(arr[element], arr[index]);
                MinHeapify(arr, arr.size(), element);
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
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    printf("\n");
    h.deleteFromHeap();
    h.print();

    std::array<int, 6> array = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n/2; i > 0; i--)
    {
        h.MaxHeapify(array, n, i);
    }

    // for (int i = n/2-1; i >= 0; i--)
    // {
    //     h.MinHeapify(array, n, i);
    // }
    std::cout << "\nafter heapify....\n\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << array[i] << " ";
    } std::cout << std::endl;

    return 0;
}