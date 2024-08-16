class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = 0,j=0;
        /*if(m == 0)
        {
            for(int i=0;i<n;i++)
            {
                nums1[i] = nums2[i];
            }
        }
        else{
        while(i<m && j<n)
        {
            if(nums1[i] > nums2[j])
            {    swap(nums1[i],nums2[j]);
            j++;
            
        }
             else if(nums1[i] == 0)
            {
                nums1[i]=nums2[j];
                i++;
                j++;
            }
          else if(nums1[i] <= nums2[j])
              i++;
           
        }
         sort(nums2.begin(),nums2.end()); */
        
        for(int i=m;i<n+m;i++)
            nums1[i] = nums2[i-m];
        sort(nums1.begin(),nums1.end());
        

    }
};