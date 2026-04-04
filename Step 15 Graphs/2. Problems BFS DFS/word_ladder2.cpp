#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> answer;
    int b;


    void dfs(string word, string beginWord,  vector<string> &path){
        if(word == beginWord){
            vector<string> res = path;
            reverse(res.begin(), res.end());
            answer.push_back(res);
            return;
        }

        int sz = word.size();
        int steps = mp[word];

        for(int i=0; i<sz; i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(mp.count(word) && mp[word]== steps-1){
                        path.push_back(word);
                        dfs(word, beginWord, path);
                        path.pop_back();
                    }
                }
                word[i] = original;
            }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        b = wordList.size();

        queue<string> q;
        q.push(beginWord);
        
        st.erase(beginWord);
        mp[beginWord] = 1;
        int sz = beginWord.size();

        while(!q.empty()){

            string word = q.front();
            q.pop();
            int steps = mp[word];

            if(word == endWord) break;

            for(int i=0; i<sz; i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        mp[word] = steps+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
            
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, beginWord, path);
        }

        return answer;
    }
};

int main() {
    Solution sol;
    
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);
    
    cout << "Word Ladders:\n";
    for(auto& ladder : result) {
        for(auto& word : ladder) {
            cout << word << " ";
        }
        cout << "\n";
    }
    
    return 0;
}