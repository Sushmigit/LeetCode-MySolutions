class Solution {
public:
    void moveZeroes(vector<int>& nums) {
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
      
        /*for(int i=cnt;i<n;i++)
            temp.push_back(0);*/
        for(int i=0;i<n;i++)
            nums[i] = temp[i];
    } 
};