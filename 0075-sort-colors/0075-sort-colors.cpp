class Solution {
public:
void better(vector<int>&nums)
{
    int cnt0=0,cnt1=0,cnt2=0;
    int i;
    for(i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        cnt0++;
        else if(nums[i]==1)
        cnt1++;
        else
        cnt2++;
    }
    for(i=0;i<cnt0;i++)
    nums[i]=0;
    for(i=cnt0;i<cnt0+cnt1;i++)
    nums[i]=1;
    for(i=cnt0+cnt1;i<nums.size();i++)
    nums[i]=2;

    
}
void dutchNationalFlag(vector<int>&nums)
{
    int low=0,high=nums.size()-1;int mid=0;
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid]==1)
        mid++;
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
    void sortColors(vector<int>& nums) {
        //better(nums); TC->O(2n) SC->O(1)
        dutchNationalFlag(nums);//TC->O(n) SC->O(!)
    }
};