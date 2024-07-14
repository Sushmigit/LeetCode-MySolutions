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
    vector<int> mooreVotingAlgo(vector<int>& nums)
    {
        int ele1 =-1,ele2 =-1,cnt1=0,cnt2=0;
        int i;
        int n = nums.size();
        for(i=0;i<n;i++)
        {
            if(cnt1 == 0 && nums[i]!=ele2)
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i]!=ele1)
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1)
                cnt1++;
            else if(nums[i] == ele2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ans;
        cnt1 = 0;cnt2 = 0;
        for(i=0;i<n;i++)
        {
            if(ele1 == nums[i]) cnt1++;
            if(ele2 == nums[i]) cnt2++;
        }
        if(cnt1 > n/3)
            ans.push_back(ele1);
        if(cnt2 > n/3 && ele1!=ele2)
            ans.push_back(ele2);
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
       //return naiveApproach(nums);//TC->O(N*N) SC->O(N)
        //return usingHash(nums);//TC->O(N) SC->O(N)+O(N)
        return mooreVotingAlgo(nums);
    }
};