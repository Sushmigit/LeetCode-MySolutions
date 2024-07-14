class Solution {
public:
    int naiveApproach(vector<int>& nums)
    {
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
    int usingHash(vector<int>& nums)
    {
        map<int,int>mpp;
        int i,n = nums.size();
        int ans = 0;
        for(i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(mpp[nums[i]]>n/2)
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
    int mooreVotingAlgo(vector<int>& nums)
    {
        int ele = -1,cnt=0,i,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
            }
            else if(ele == nums[i])
                cnt++;
            else
                cnt--;
        }
        return ele;
    }
    int majorityElement(vector<int>& nums) {
      
        //return naiveApproach(nums);//TC->O(N*N) SC->O(1)
        //return usingHash(nums);//TC->O(N) SC->O(N)
        return mooreVotingAlgo(nums);
    }
};