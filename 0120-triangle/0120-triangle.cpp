class Solution {
public:
    int func(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i == n-1)
            return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d = triangle[i][j] + func(i+1,j,n,triangle,dp);
        int dg = triangle[i][j] + func(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(d,dg);
    }
    int tabulation(vector<vector<int>>& triangle)
    {
         int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            dp[n-1][i] = triangle[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d = triangle[i][j] + func(i+1,j,n,triangle,dp);
                int dg = triangle[i][j] + func(i+1,j+1,n,triangle,dp);
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            dp[n-1][i] = triangle[n-1][i];
        /*func(0,0,n,triangle,dp);
        return dp[0][0];*/
        return tabulation(triangle);
    }
};