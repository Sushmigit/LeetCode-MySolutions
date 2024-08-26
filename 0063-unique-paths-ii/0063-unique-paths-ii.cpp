class Solution {
public:
    int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i >= 0 && j>=0 && grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return dp[i][j] =  1;
        if(i < 0 || j < 0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = func(i-1,j,grid,dp)+func(i,j-1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        //return func(m-1,n-1,obstacleGrid,dp);//Memoization from recursion
        //Tabulation
       /* for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                 
                else
                {
                    int up = 0;
                    int left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];*/
        //Space Optimization
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1) temp[j] = 0;
                else if(i == 0 && j == 0) temp[j] = 1;
                 
                else
                {
                   temp[j] = prev[j] ;
                   if(j > 0)
                   temp[j] += temp[j-1];
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};