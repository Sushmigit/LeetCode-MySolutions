class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        vector<int>ans(n);
       /* for(int i=0;i<n;i++)
        {
            if(nums[i] % 2 == 1)
                odd++;
        }*/
        int ind = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] % 2 == 0)
                ans[ind++] = nums[i];
        }
        for(int i = 0;i<n;i++)
        {
            if(nums[i] % 2 == 1)
                ans[ind++] = nums[i];
        }
        return ans;
    }
};