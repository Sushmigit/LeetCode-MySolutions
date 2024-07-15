class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
         vector<vector<int>>ans(n,vector<int>(n,0));
         int i,j;
         for(i=0;i<n;i++)//TC->O(N*M) SC->O(N*M)
         {
             for(j=0;j<n;j++)
             {
                 ans[j][n-i-1] = matrix[i][j];
             }
         }
      matrix = ans;
    }
};