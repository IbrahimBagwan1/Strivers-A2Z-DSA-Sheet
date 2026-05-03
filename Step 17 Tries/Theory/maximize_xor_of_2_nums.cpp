// we want to maximize
// x = 8

// insert all the array elements in to the trie in the form of bits.
// take x ith bit and find the opposite to that ith bit in the trie, and then go ahead, if not found then go with the same bit, lastly you will get all the path with the max, store that path simultaneously and then convert it to number and return.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Define the Trie Node Structure
struct Node {
    Node* links[2]; // links[0] for bit 0, links[1] for bit 1

    // Checks if the current bit path exists
    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    // Returns the node at the specific bit path
    Node* get(int bit) {
        return links[bit];
    }

    // Creates a new node at the specific bit path
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

    // Inserts a number into the Trie at the bit level (31 to 0)
    void insert(int num) {
        Node* node = root;
        // Start from the most significant bit (31st bit)
        for (int i = 31; i >= 0; i--) {
            // Extract the ith bit of the number
            int bit = (num >> i) & 1;
            
            // If the path doesn't exist, create it
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            // Move to the next node
            node = node->get(bit);
        }
    }

    // Finds the maximum XOR for a given number using the greedy approach
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            // We want the OPPOSITE bit to maximize XOR (1 ^ 0 = 1, 0 ^ 1 = 1)
            int oppositeBit = 1 - bit; 
            
            if (node->containsKey(oppositeBit)) {
                // If opposite bit exists, we secure a '1' at the ith position of our result
                // (1 << i) sets the ith bit to 1 in maxNum
                maxNum = maxNum | (1 << i);
                
                // Move down the path of the opposite bit
                node = node->get(oppositeBit);
            } else {
                // If opposite bit doesn't exist, we are forced to take the same bit
                // This results in a '0' at the ith position of our XOR result (which is already 0 by default)
                // Move down the only available path
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// 3. Main Solution Class
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        
        // Step 1: Insert all numbers into the Trie
        for (int num : nums) {
            trie.insert(num);
        }
        
        int maxi = 0;
        
        // Step 2: Find the max XOR for each number and keep the global maximum
        for (int num : nums) {
            maxi = max(maxi, trie.getMax(num));
        }
        
        return maxi;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    int result1 = solution.findMaximumXOR(nums1);
    cout << "Example 1 Output: " << result1 << " (Expected: 28)" << endl;

    // Example 2
    vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    int result2 = solution.findMaximumXOR(nums2);
    cout << "Example 2 Output: " << result2 << " (Expected: 127)" << endl;

    return 0;
}