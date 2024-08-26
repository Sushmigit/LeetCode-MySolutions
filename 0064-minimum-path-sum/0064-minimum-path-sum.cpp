class Solution {
public:
     int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
       
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0 ) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = func(i-1,j,grid,dp);
        int left = func(i,j-1,grid,dp);
        return dp[i][j] = grid[i][j] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
       // return func(m-1,n-1,grid,dp);//Memoization from recursion
       /*for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(up,left);
                }
            }
        }
        return dp[m-1][n-1];*/
         //Space Optimization
        vector<int>prev(n,INT_MAX);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
               
                if(i == 0 && j == 0) temp[j] = grid[0][0];
                 
                else
                {
                   int up = (i>0) ? prev[j] : INT_MAX;
                    int left = (j>0) ? temp[j-1] : INT_MAX;
                    temp[j] = grid[i][j] + min(up,left);
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};