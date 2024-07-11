class Solution {
public:
    vector<int> usingMinHeap(vector<int>& nums, int k)
    {
        map<int,int>mpp;
        int i;
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(i=0;i<nums.size();i++)//O(N)
            mpp[nums[i]]++;
        for(auto it:mpp)//O(N logK)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())//O(KlogK)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return usingMinHeap(nums,k);//TC->O(N logK) SC->O(N)+O(K)
    }
};