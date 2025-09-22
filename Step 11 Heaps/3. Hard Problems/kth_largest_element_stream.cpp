#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;

    KthLargest(int kth, vector<int>& nums) {
        k = kth;
        for (int ele : nums) {
            pq.push(ele);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top(); // smallest in heap = k-th largest overall
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest kthLargest(k, nums);

    cout << kthLargest.add(3) << endl;  // output: 4
    cout << kthLargest.add(5) << endl;  // output: 5
    cout << kthLargest.add(10) << endl; // output: 5
    cout << kthLargest.add(9) << endl;  // output: 8
    cout << kthLargest.add(4) << endl;  // output: 8

    return 0;
}
