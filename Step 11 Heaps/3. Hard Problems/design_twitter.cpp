#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    struct Tweet{
        int time;
        int id;
        Tweet (int t, int i) : time(t), id(i){}
    };

    int timeStamp;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(timeStamp++, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<vector<int>> pq;

        // Push the most recent tweet of the user
        if(tweets.count(userId)){
            auto &t = tweets[userId];
            int idx = (int)t.size()-1;
            pq.push({t[idx].time, t[idx].id, userId, idx});
        }

        // Push the most recent tweet of each followee
        for(int f : follows[userId]){
            if(tweets.count(f)){
                auto &t = tweets[f];
                int idx = (int)t.size()-1;
                pq.push({t[idx].time, t[idx].id, f, idx});
            }
        }

        // Collect top 10 tweets
        while(!pq.empty() && (int)feed.size() < 10){
            auto top = pq.top(); pq.pop();
            feed.push_back(top[1]);
            
            int user = top[2];
            int idx = top[3];

            // Push the next older tweet of the same user
            if(idx > 0){
                auto &t = tweets[user][idx-1];
                pq.push({t.time, t.id, user, idx-1});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;

    // User 1 posts a tweet
    twitter.postTweet(1, 101);
    twitter.postTweet(1, 102);

    // User 2 posts a tweet
    twitter.postTweet(2, 201);
    twitter.postTweet(2, 202);

    // User 1 follows User 2
    twitter.follow(1, 2);

    // Get news feed for User 1
    vector<int> feed = twitter.getNewsFeed(1);
    cout << "User 1's feed: ";
    for(int id : feed) cout << id << " ";
    cout << endl;

    // User 1 unfollows User 2
    twitter.unfollow(1, 2);

    // Get news feed again
    feed = twitter.getNewsFeed(1);
    cout << "User 1's feed after unfollowing: ";
    for(int id : feed) cout << id << " ";
    cout << endl;

    return 0;
}
