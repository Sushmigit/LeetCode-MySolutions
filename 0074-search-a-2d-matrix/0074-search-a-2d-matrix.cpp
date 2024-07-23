class Solution {
public:
    bool binarySearch(vector<int>&nums,int target)
{
   int low = 0,high=nums.size()-1;
   while(low<=high)
   {
    int mid=(low+high)/2;
    if(nums[mid]==target)
    return true;
    else if(nums[mid]<target)
    low=mid+1;
    else
    high=mid-1;
   }
   return false;
}
    bool better(vector<vector<int>>& mat, int target)
    {
        int i,m=mat[0].size();
        for(i=0;i<mat.size();i++)
        {
            if(target>=mat[i][0] && target<=mat[i][m-1])
                return binarySearch(mat[i],target);
        }
        return false;
    }
    bool optimal(vector<vector<int>>& matrix, int target)
    {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m,col=mid%m;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                low = mid+1;
            else
                high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //return better(matrix,target);
        return optimal(matrix,target);
    }
};