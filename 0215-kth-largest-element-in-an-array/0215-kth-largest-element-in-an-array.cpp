class Solution {
public:
    int usingSort(vector<int> &nums,int k)
    {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return usingSort(nums,k);
    }
};