class Twitter {
public:
    map<int,set<int>>mpp;
    int time;
    priority_queue<vector<int>>pq;
    Twitter() {
        time = 0;
        pq = priority_queue<vector<int>>();
        mpp.clear();
    }
    
    void postTweet(int userId, int tweetId) {//TC->O(log n) SC->O(n)(pq)
        pq.push({time++,userId,tweetId});
    }
     
    vector<int> getNewsFeed(int userId) {//TC->O(n+10 log n) SC->O(n)copied pq(user)
        vector<int>ans;
        int n = 0;
        priority_queue<vector<int>>user = pq;
        while(!user.empty() && n<10)
        {
            auto topTweet = user.top();
            user.pop();
            if(topTweet[1] == userId || mpp[userId].count(topTweet[1]))
            {
                ans.push_back(topTweet[2]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {//TC->O(log F) SC->O(n)mpp
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {//TC->O(log F) SC->O(n)mpp
        mpp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */