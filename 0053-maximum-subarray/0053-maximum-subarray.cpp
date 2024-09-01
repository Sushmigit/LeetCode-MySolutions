class Solution {
public:
int brute(vector<int>&nums)
{
    int sum,maxi=INT_MIN,n=nums.size();int i,j;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
        
    }
    return maxi;
}
int kadane(vector<int>&nums)
{
    int i;int sum=0;int maxi=INT_MIN,max_neg=INT_MIN;
    for(i=0;i<nums.size();i++)
    {
         sum+=nums[i];
         max_neg=max(nums[i],max_neg);
         if(sum<0)
         sum=0;
         maxi=max(sum,maxi);
        
    }
    if(maxi==0)
    return max_neg;
    return maxi;
}
    int maxSubArray(vector<int>& nums) {
        //return brute(nums);
        return kadane(nums);
    }
};