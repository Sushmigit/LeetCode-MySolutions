class Solution {
public:
    //TC->O(N*M) SC->O(N+M)
    string multiply(string nums1, string nums2) {
        if(nums1 == "0" || nums2 == "0")
            return "0";
        int n = nums1.size(),m=nums2.size();
        vector<int>nums(n+m,0);
        int i,j;
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                int mul = (nums1[i]-'0')*(nums2[j]-'0');
               int sum = nums[i+j+1]+mul;
                nums[i+j]+=(sum/10);//carry is added to the prev value
                nums[i+j+1]=sum%10;//sum is added to the cur index
            }
        }
       
       string s = "";
        for (int num : nums)
        {//Removing leading zeroes and transform vector to string
            if(!(s.empty() && num == 0))
            {
                s.push_back(num + '0');
            }
        }
        return s.empty() ? "0" : s;
    }
    
};