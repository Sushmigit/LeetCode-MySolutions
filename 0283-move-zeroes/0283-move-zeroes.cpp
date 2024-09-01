class Solution {
public:
    /*void brute(vector<int>& nums)
    {
         int cnt = 0,n = nums.size();
        vector<int>temp(n,0);
        int ind = 0;
       for(int i=0;i<n;i++)
       {
           if(nums[i]!=0)
           {
               temp[ind++] = nums[i];
               cnt++;
           }
       }
      
        //for(int i=cnt;i<n;i++)
            //temp.push_back(0);
        for(int i=0;i<n;i++)
            nums[i] = temp[i];
    }*/
    void moveZeroes(vector<int>& nums) {
        int cnt = 0,n = nums.size();
        int i,j;
        //brute(nums);
        for(int k = 0;k<n;k++)
        {
            if(nums[k]==0)
            {
                i = k;
                break;
            }
        }
        j = i+1;
        while(j<n && i<n)
        {
            if(nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;
                
            }
            j++;
        }
    } 
};