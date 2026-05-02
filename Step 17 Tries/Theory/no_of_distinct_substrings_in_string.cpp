#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];

    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Solution{	
public:
    int countDistinctSubstring(string s){
        int n = s.size();
        Node* root = new Node();
        int count = 0;

        for(int i = 0; i < n; i++){
            Node* node = root;
            for(int j = i; j < n; j++){
                if(!node->containsKey(s[j])){
                    count++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }

        return count + 1; // +1 for empty substring
    }
};

int main(){
    Solution obj;

    string s = "ababa";

    int result = obj.countDistinctSubstring(s);

    cout << result;

    return 0;
}