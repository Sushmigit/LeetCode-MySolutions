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
            if(cnt>n/3)
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
    vector<int> usingHash(vector<int>& nums)
    {
        map<int,int>mpp;
        vector<int>ans;
        int i,n=nums.size();
        for(i=0;i<n;i++)
            mpp[nums[i]]++;
       for(auto it=mpp.begin();it!=mpp.end();it++)
       {
          if(it->second > n/3)
              ans.push_back(it->first);
       }
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
       //return naiveApproach(nums);//TC->O(N*N) SC->O(N)
        return usingHash(nums);
    }
};