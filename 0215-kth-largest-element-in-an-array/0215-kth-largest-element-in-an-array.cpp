class Solution {
public:
    int usingSort(vector<int> &nums,int k)
    {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
    int usingMaxHeap(vector<int> &nums,int k)
    {
        priority_queue<int>maxpq;
        int i;
        for(i=0;i<nums.size();i++)
        {
            maxpq.push(nums[i]);
        }
        while(k>1)
        {
            maxpq.pop();
            k--;
        }
        return maxpq.top();
    }
    int findKthLargest(vector<int>& nums, int k) {
        //return usingSort(nums,k);//TC->O(NlogN) SC->O(1)
        return usingMaxHeap(nums,k);
    }
};