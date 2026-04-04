#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        st.insert(wordList.begin(), wordList.end());
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(str == endWord) return steps;

            for(int i=0; i<str.size(); i++){
                char original = str[i];
                for(char ch='a'; ch<='z'; ch++){
                    str[i] = ch;
                    if(st.find(str) != st.end()){
                        st.erase(str);
                        q.push({str, steps+1});
                    }
                }
                str[i] = original;
            }
            
        }
        return 0;
    }
};

int main() {
    Solution sol;
    
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Word Ladder Length: " << result << endl;
    
    return 0;
}
