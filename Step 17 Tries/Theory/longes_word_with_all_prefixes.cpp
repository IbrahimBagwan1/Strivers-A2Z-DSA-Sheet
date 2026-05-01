#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag;

    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
        flag = false;
    }

    bool containKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void setKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* goNext(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containKey(ch)) {
                node->setKey(ch, new Node());
            }
            node = node->goNext(ch);
        }
        node->setEnd();
    }

    // Check if ALL prefixes exist
    bool checkAllPrefixes(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containKey(ch)) return false;
            node = node->goNext(ch);
            if(!node->isEnd()) return false; // prefix must exist
        }
        return true;
    }
};

class Solution {
public:
    string completeString(vector<string>& nums) {
        Trie trie;

        for(string &word : nums) {
            trie.insert(word);
        }

        string ans = "";

        for(string &word : nums) {
            if(trie.checkAllPrefixes(word)) {
                if(word.length() > ans.length()) {
                    ans = word;
                }
                else if(word.length() == ans.length() && word < ans) {
                    ans = word;
                }
            }
        }

        if(ans == "") return "None";
        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> nums = {"n", "ni", "nin", "ninj", "ninja", "ninga"};

    string result = obj.completeString(nums);

    cout << result;

    return 0;
}