class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int>st(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        if(st.size() < 3)
        {
            int maxi = INT_MIN;
            for(int i=0;i<nums.size();i++)
                maxi = max(maxi,nums[i]);
            return maxi;
        }
        for(auto it:st)
        {
            pq.push(it);
            if(pq.size() > 3)
                pq.pop();
        }
        return pq.top();
    }
};