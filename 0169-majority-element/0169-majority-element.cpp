class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int i,n=nums.size(),j,cnt=0,ans;
        for(i=0;i<n;i++)
        {
            cnt = 0;
            for(j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                cnt++;
            }
            if(cnt>n/2)
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};