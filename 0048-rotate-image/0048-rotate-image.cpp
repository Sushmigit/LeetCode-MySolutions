class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        //Naive Approach
         /*vector<vector<int>>ans(n,vector<int>(n,0));
         int i,j;
         for(i=0;i<n;i++)//TC->O(N*M) SC->O(N*M)
         {
             for(j=0;j<n;j++)
             {
                 ans[j][n-i-1] = matrix[i][j];
             }
         }
      matrix = ans;*/
        //Optimal Approach
        //Transpose of the matrix
        int i,j;
        //O(n/2*n/2)->O(n^2)
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Reverse each row
        //O(n^2)
        for(i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};