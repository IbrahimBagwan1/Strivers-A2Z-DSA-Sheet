#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to heapify at index i for max-heap
    void heapifyMax(vector<int>& nums, int i, int n) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && nums[left] > nums[largest])
            largest = left;
        if(right < n && nums[right] > nums[largest])
            largest = right;

        if(largest != i) {
            swap(nums[i], nums[largest]);
            heapifyMax(nums, largest, n);
        }
    }

    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--) {
            heapifyMax(nums, i, n);
        }
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> minHeap = {1, 3, 5, 7, 9, 6};
    vector<int> maxHeap = sol.minToMaxHeap(minHeap);

    cout << "Max-Heap array: ";
    for(int x : maxHeap) cout << x << " ";
    cout << endl;

    return 0;
}
