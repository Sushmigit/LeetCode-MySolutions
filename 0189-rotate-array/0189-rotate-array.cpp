class Solution {
public:
 void brute(vector<int>& nums, int k)
 {
      k=k%nums.size();
        int n = nums.size();
        vector<int>temp;
        for(int i=n-1;i>=n-k;i--)
            temp.push_back(nums[i]);
        reverse(temp.begin(),temp.end());
        for(int i=0;i<n-k;i++)
            temp.push_back(nums[i]);
        for(int i=0;i<n;i++)
            nums[i] = temp[i];
 }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n = nums.size();
        //brute(nums,k);
         reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
       
    }
};