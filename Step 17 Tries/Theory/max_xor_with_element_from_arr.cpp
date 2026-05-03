#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Define the Trie Node Structure
struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

// 2. Define the Trie Class
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit; 
            
            if (node->containsKey(oppositeBit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(oppositeBit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// 3. Main Solution Class
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Step 1: Sort the nums array to process constraints in ascending order
        sort(nums.begin(), nums.end());
        
        int q = queries.size();
        // Create an offline queries array to keep track of the original index
        // Format: {m_i (threshold), x_i (value to XOR), original_index}
        vector<vector<int>> offlineQueries(q, vector<int>(3));
        for (int i = 0; i < q; i++) {
            offlineQueries[i][0] = queries[i][1];
            offlineQueries[i][1] = queries[i][0];
            offlineQueries[i][2] = i; 
        }
        
        // Step 2: Sort the queries based on the threshold 'm_i'
        sort(offlineQueries.begin(), offlineQueries.end());
        
        vector<int> ans(q, 0);
        Trie trie;
        int idx = 0;
        int n = nums.size();
        
        // Step 3: Iterate through sorted queries and incrementally build the Trie
        for (int i = 0; i < q; i++) {
            int mi = offlineQueries[i][0];
            int xi = offlineQueries[i][1];
            int qInd = offlineQueries[i][2];
            
            // Insert elements into Trie ONLY if they are <= current query's threshold
            while (idx < n && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }
            
            // If the Trie is empty (no elements <= mi were found), return -1 as per requirements
            if (idx == 0) {
                ans[qInd] = -1;
            } else {
                // Otherwise, get the max XOR from the currently available elements
                ans[qInd] = trie.getMax(xi);
            }
        }
        
        return ans;
    }
};

// 4. Main Function to test
int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {0, 1, 2, 3, 4};
    vector<vector<int>> queries1 = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> result1 = solution.maximizeXor(nums1, queries1);
    
    cout << "Example 1 Output: [";
    for(int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [3, 3, 7])\n";

    // Example 2
    vector<int> nums2 = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> queries2 = {{12, 4}, {8, 1}, {6, 3}};
    vector<int> result2 = solution.maximizeXor(nums2, queries2);
    
    cout << "Example 2 Output: [";
    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [15, -1, 5])\n";

    return 0;
}