// Q. https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Heap {
    public:
        // std::priority_queue<int> maxHeap;
        // std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        // One another way to create min-heap is whenever you insert any data, multiply it by -1.
        // also pop out those elements with multiplying by -1

        std::vector<int> nodes;
        int size;

        Heap() {
            nodes.reserve(100);
            nodes[0] = -1;
            size = 0;
        }

    public:
        // TC -> O(logn)
        void insert(int val) {
            size++; // index no 1
            int index = size;
            nodes[index] = val;

            while(index > 1) {
                int parent = index/2; // find parent index

                // swapping
                if(nodes[parent] < nodes[index]) {
                    std::swap(nodes[parent], nodes[index]);
                    index = parent;
                }
                else {
                    return;
                }
            }
        }

        // TC -> O(logn)
        void deleteNodeFromHeap() {
            if(size == 0) {
                std::cout << "Nothing to delete!\n";
                return;
            }

            // step:1 put the last index value to the root index
            nodes[1] = nodes[size];
            size--;

            int i = 1;
            while(i < size) {
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;

                if(leftIndex < size && nodes[i] < nodes[leftIndex]) {
                    std::swap(nodes[leftIndex], nodes[i]);
                    i = leftIndex;
                }
                else if(rightIndex < size && nodes[i] < nodes[rightIndex]) {
                    std::swap(nodes[rightIndex], nodes[i]);
                    i = rightIndex;
                }
                else {
                    return;
                }
            }
        }

        // TC -> O(logn)
        void maxHeapify(std::vector<int>& nodes, int size, int index) {
            int largest = index;
            int leftNodeIndex = 2 * index;
            int rightNodeIndex = 2 * index + 1;

            if(leftNodeIndex <= size && nodes[largest] < nodes[leftNodeIndex]) {
                largest = leftNodeIndex;
            }

            if(rightNodeIndex <= size && nodes[largest] < nodes[rightNodeIndex]) {
                largest = rightNodeIndex;
            }


            if(largest != index) {
                std::swap(nodes[largest], nodes[index]);
                maxHeapify(nodes, size, largest);
            }
        }

        void minHeapify(std::vector<int>& nodes, int size, int index) {
            int smallest = index;
            int leftNodeIndex = 2 * index + 1;
            int rightNodeIndex = 2 * index + 2;

            if(leftNodeIndex < size && nodes[smallest] > nodes[leftNodeIndex]) {
                smallest = leftNodeIndex;
            }

            if(rightNodeIndex < size && nodes[smallest] > nodes[rightNodeIndex]) {
                smallest = rightNodeIndex;
            }

            if(smallest != index) {
                std::swap(nodes[smallest], nodes[index]);
                minHeapify(nodes, size, smallest);
            }
        }

        // TC -> O(nlogn)
        void heapSort(std::vector<int>& nodes, int size) {
            int t = size;

            while (t > 1) {
                std::swap(nodes[t], nodes[1]);
                t--;

                maxHeapify(nodes, t, 1);
            }
        }

        void print() {
            for(int i = 1; i <= size; i++) {
                std::cout << nodes[i] << " ";
            }std::cout << std::endl;
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

    h.deleteNodeFromHeap();
    h.print();


    std::vector<int> nodes {-1, 54, 53, 55, 52, 50};
    int n = nodes.size();

    // for(int i = n/2; i > 0; i--) {
    //     h.maxHeapify(nodes, n, i);
    // }

    for(int i = n/2; i > 0; i--) {
        h.minHeapify(nodes, n, i);
    }

    std::cout << "Printing now....\n";
    for(int i = 1; i < n; i++) {
        std::cout << nodes[i] << " ";
    }std::cout << std::endl;

    //h.heapSort(nodes, n);
    std::make_heap(nodes.begin() + 1, nodes.end());
    std::sort_heap(nodes.begin() + 1, nodes.end());

    std::cout << "After Heap sort....\n";
    for(int i = 1; i < n; i++) {
        std::cout << nodes[i] << " ";
    }std::cout << std::endl;

    return 0;
}