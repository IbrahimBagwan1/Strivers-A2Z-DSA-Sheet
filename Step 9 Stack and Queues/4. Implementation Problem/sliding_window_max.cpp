#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windowMax;
        deque<int> dq;

        for(int i=0; i<n; i++){
            // remove smaller elements from back
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);

            int j = i - k + 1; // window start index

            // remove indices outside the window
            while(!dq.empty() && dq.front() < j) dq.pop_front();

            // add maximum of current window
            if(j >= 0){
                windowMax.push_back(nums[dq.front()]);
            }
        }
        return windowMax;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding window maximums: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
