#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> arr;  // our heap array

public:
    void initializeHeap() {
        arr.clear();
    }

    // Heapify (restore heap property) at index i
    void heapify(int i) {
        int n = arr.size();
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;
        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // Insert a new key
    void insert(int key) {
        arr.push_back(key);
        int i = arr.size() - 1;

        // Bubble up
        while (i != 0 && arr[(i-1)/2] > arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    // Change value at index and restore heap
    void changeKey(int index, int new_val) {
        arr[index] = new_val;

        // If new value is smaller, bubble up
        while (index != 0 && arr[(index-1)/2] > arr[index]) {
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }

        // Otherwise, heapify down
        heapify(index);
    }

    // Remove and return min element
    int extractMin() {
        if (arr.size() == 0) return INT_MAX;
        if (arr.size() == 1) {
            int root = arr[0];
            arr.pop_back();
            return root;
        }

        int root = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        heapify(0);
        return root;
    }

    // Check if heap is empty
    bool isEmpty() {
        return arr.empty();
    }

    // Return min element
    int getMin() {
        if (arr.empty()) return INT_MAX;
        return arr[0];
    }

    // Return heap size
    int heapSize() {
        return arr.size();
    }

    // Utility: print heap
    void printHeap() {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

int main() {
    Solution heap;
    heap.initializeHeap();

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(3);
    heap.insert(15);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Minimum element: " << heap.getMin() << endl;

    cout << "Extracted min: " << heap.extractMin() << endl;

    cout << "Heap after extract: ";
    heap.printHeap();

    heap.changeKey(2, 2);
    cout << "Heap after changeKey: ";
    heap.printHeap();

    return 0;
}
