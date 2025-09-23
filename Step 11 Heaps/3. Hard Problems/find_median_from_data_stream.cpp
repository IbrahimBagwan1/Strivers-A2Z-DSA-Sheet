#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;  // max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;  // min-heap for larger half

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Put num in correct heap
        if(leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }

        // Step 2: Balance heaps
        if(leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if(rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()) {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        } else {
            return leftMaxHeap.top(); // left heap has one more
        }
    }
};

int main() {
    MedianFinder mf;

    vector<int> nums = {1, 2, 3, 4, 5};
    for(int num : nums) {
        mf.addNum(num);
        cout << "After inserting " << num << ", median = " << mf.findMedian() << endl;
    }

    return 0;
}
