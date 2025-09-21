#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int N = tasks.size();
        vector<int> mp(26,0);

        // Count frequency of each task
        for(int i=0; i<N; i++){
            mp[tasks[i]-'A']++;
        }

        // Max heap to always pick task with highest frequency
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(mp[i]>0) pq.push(mp[i]);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            
            // One cycle of length (n+1)
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top(); pq.pop();
                    freq--;   // one execution done
                    temp.push_back(freq);
                }
            }

            // Push back unfinished tasks
            for(int f: temp){
                if(f>0) pq.push(f);
            }

            // Add time
            if(pq.empty()) time += temp.size();
            else time += (n+1);
        }
        return time;
    }
};

int main() {
    Solution sol;

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << "Minimum intervals required: " 
         << sol.leastInterval(tasks, n) << endl;

    return 0;
}
