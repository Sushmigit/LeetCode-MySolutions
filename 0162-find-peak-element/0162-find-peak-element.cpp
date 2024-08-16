class Solution {
public:
    int brute(vector<int>& nums)
    {
        int n = nums.size();
        if( n == 1)
            return 0;
      for(int i=1;i<n-1;i++)
      {
          if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
              return i;
      }
        if(nums[0] > nums[1])
            return 0;
        if(nums[n-1] > nums[n-2])
            return n-1;
       return 0;
    }
    int usingBN(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1)
            return 0;
        if(nums[0] > nums[1])
            return 0;
        if(nums[n-1] >nums[n-2])
            return n-1;
        int l = 1,h=n-2,mid;
        while(l<=h)
        {
            mid = (l+h)/2;
           if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
               return mid;
           else if(nums[mid] < nums[mid-1])
                 h = mid-1;
            else 
                l = mid+1;
               
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        //return brute(nums);
        return usingBN(nums);
    }
};