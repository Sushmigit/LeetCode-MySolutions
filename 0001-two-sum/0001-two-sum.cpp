class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>arr;
        map<int,int>mpp;int i;
    for(i=0;i<nums.size();i++)
    {
        int rem=target-nums[i];
        if(mpp.find(rem)!=mpp.end())
        {
           arr.push_back(i);
           arr.push_back(mpp[rem]);
        }
        mpp[nums[i]]=i;
    }
return arr ;
    }
};