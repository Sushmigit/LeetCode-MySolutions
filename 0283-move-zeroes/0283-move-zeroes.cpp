class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0,n = nums.size();
        if(n > 1)
        {    
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            cnt++;
        }
            
        int ind = 0;
       /* for(int i=0;i<n1;i++)
        {
            if(nums[i] == 0)
            {
                for(int j=i;j<n1;j++)
                {
                    nums[j] = nums[j+1];
                }
               
            }
        }*/
        for(int i = 0;i<n;i++)
        {
           if(nums[i]!=0)
               nums[ind++] = nums[i];
        }
            for(int i = ind;i<n;i++)
            {
                nums[i] = 0;
            }
        }
    }
};