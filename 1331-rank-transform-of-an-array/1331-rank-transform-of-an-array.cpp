class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
         vector<int>ans(n);
        if(n == 0)
            return ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++)
            pq.push({arr[i],i});
        int rank = 1;
        int prev = pq.top().first;
        int ind = pq.top().second;
        int val = pq.top().first;
       
        ans[ind] = rank;
        pq.pop();
        while(!pq.empty())
        {
            int ind = pq.top().second;
            int val = pq.top().first;
            if(val == prev)
               ans[ind] = rank;
            else
                ans[ind] = ++rank;
            prev = val;
            pq.pop();
        }
        return ans;
    }
};