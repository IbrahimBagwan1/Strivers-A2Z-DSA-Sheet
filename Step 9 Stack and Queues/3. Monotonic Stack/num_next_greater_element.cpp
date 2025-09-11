#include<bits/stdc++.h>
using namespace std;

vector<int> numberNextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        vector<int> nextGreater(n,0);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            int current = nums2[i];
            while(!st.empty() && current > st.top()){
                st.pop();
            }

            if(!st.empty()) nextGreater[i] = st.size();
            
            st.push(current);
        }

        return nextGreater;
}


    
int main() {
    vector<int> nums1; // unused, preserved to match signature
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = numberNextGreaterElement(nums1, nums2);

    cout << "Counts of successive next-greater elements for nums2: ";
    for (int x : ans) cout << x << " ";
    cout << "\n"; // Expected output: 2 1 0 0

    return 0;
}