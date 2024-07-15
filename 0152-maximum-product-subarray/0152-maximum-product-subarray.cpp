class Solution {
public:
    int naive(vector<int>& nums)
    {
        int i,j,n=nums.size();
        long long maxi = INT_MIN;
        for(i=0;i<n;i++)
        {
            long long pro = 1;
            for(j=i;j<n;j++)
            {
                pro*=nums[j];
                if(pro<INT_MIN) pro=1;
                maxi=max(maxi,pro);
            }
        }
        return maxi;
    }
    int preSuf(vector<int>& nums)
    {
        long long pre=1,suf=1;
        int i,n=nums.size();
        long long maxi = LLONG_MIN;
        for(i=0;i<n;i++)
        {
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            if(pre<INT_MIN) pre=1;
            if(suf<INT_MIN) suf=1;
            pre = pre*nums[i];
            suf = suf*nums[n-i-1];
            maxi = max(maxi,max(pre,suf));
        }
        return maxi;
    }
    int maxProduct(vector<int>& nums) {
       //return naive(nums);//TC->O(N*N) SC->O(1) TLE
        return preSuf(nums);//TC->O(N) SC->O(1)
    }
};