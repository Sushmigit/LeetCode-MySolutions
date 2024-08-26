class Solution {
public:
    int func(int i,int j,vector<vector<int>>& mat,int n,int m,vector<vector<int>>&dp)
    {
         if(i<0 || j<0 || i>=n || j>=m)
            return INT_MAX;
        if(i == 0)
            return dp[i][j] = mat[0][j];
       if(dp[i][j]!=-1) return dp[i][j];
        int up = func(i-1,j,mat,n,m,dp);
        int l = func(i-1,j-1,mat,n,m,dp);
        int r = func(i-1,j+1,mat,n,m,dp);
        return mat[i][j] + min(up,min(l,r));
    }
    int usingTabulation(vector<vector<int>>& mat)
    {
        int n = mat.size();
        
        int m = mat[0].size();
        //vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<int>prev(m,0);
        for(int i=0;i<m;i++)
            prev[i] = mat[0][i];
        for(int i=1;i<n;i++)
        {
            vector<int>temp(m,0);
            for(int j=0;j<m;j++)
            {
                int l = INT_MAX,r=INT_MAX;
                int up = prev[j];
                if(j-1 >= 0)
                l =  prev[j-1];
                if(j+1 < m)
                r =  prev[j+1];
                temp[j] = mat[i][j] + min(up,min(l,r));
            }
            prev = temp;
        }
        int mini = INT_MAX;
        for(int i=0;i<m;i++)
            mini = min(prev[i],mini);
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       /* for(int i=0;i<m;i++)
        {
           
            mini = min(mini,func(n-1,i,matrix,n,m,dp));
        } 
        return mini;*/
        return usingTabulation(matrix);
    }
};