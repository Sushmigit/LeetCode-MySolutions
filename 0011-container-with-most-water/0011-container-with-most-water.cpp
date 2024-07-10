class Solution {
public:
    int maxArea(vector<int>& height) {//TC->O(N) SC->O(1)
        int i=0,j=height.size()-1;
        int maxi=INT_MIN;int pro;
        while(i<j)
        {
            if(height[i]<=height[j])
            {
                pro = height[i]*(j-i);
               i++;
               
            }
            else
            {
                 pro = height[j]*(j-i);
                j--;
               
            }
            maxi = max(maxi,pro);
        }
        return maxi;
    }
};