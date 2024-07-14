class Solution {
public:
    vector<int> naiveApproach(vector<int>& nums)
    {
        int i,j,cnt;
        int n = nums.size();
        vector<int>ans;
        for(i=0;i<n;i++)
        {
            cnt = 0;
            for(j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                    cnt++;
            }
            if(cnt>n/3 )
            {
                if(!ans.empty())
                {
                    if(nums[i]!=ans.back())
                        ans.push_back(nums[i]);
                }
                else
                    ans.push_back(nums[i]);
            }
                
            if(ans.size()==2)
                break;
        }
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
       return naiveApproach(nums);
    }
};