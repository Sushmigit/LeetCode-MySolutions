class Solution {
public:
    vector<int> brute(vector<int>& nums)
    {
        vector<int>ans;int pro;
        int i,j,n=nums.size();
        for(i=0;i<n;i++)
        {
            pro=1;
            for(j=0;j<n;j++)
            {
                if(i==j) continue;
                pro*=nums[j];
            }
            ans.push_back(pro);
        }
        return ans;
    }
    vector<int>optimal(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>pre(n,1),suf(n,1),ans(n,1);
        int i;
        pre[0]=1;
        suf[n-1]=1;
        for(i=1;i<n;i++)//Compute prefix products for each element
            pre[i]=nums[i-1]*pre[i-1];
        for(i=n-2;i>=0;i--)//Compute suffix products for each element
            suf[i]=suf[i+1]*nums[i+1];
        for(i=0;i<n;i++)//Multiply pre and suf
            ans[i]=pre[i]*suf[i];
        return ans;
        
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        //return brute(nums);//TC->O(N^2) SC->O(N)//TLE
        return optimal(nums);//TC->O(N) SC->O(N)
    }
};