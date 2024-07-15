class Solution {
public:
    
    int lis(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp)
    {
        
        if(ind == nums.size())
            return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len = 0+lis(ind+1,prev_ind,nums,dp);//Not Picking the ele
        if(prev_ind == -1 || nums[ind]>nums[prev_ind])
            len = max(len,1+lis(ind+1,ind,nums,dp));//Pick the ele
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return lis(0,-1,nums,dp);//TC->O(N*N) SC->O(N*N)+O(N)Recursive stack space
    }
};