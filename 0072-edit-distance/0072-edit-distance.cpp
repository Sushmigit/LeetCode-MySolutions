class Solution {
public:
    
    int minDis(int i,int j,string word1, string word2,vector<vector<int>>& dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=minDis(i-1,j-1,word1,word2,dp);
        return dp[i][j]=1+min(minDis(i,j-1,word1,word2,dp),min(minDis(i-1,j,word1,word2,dp),minDis(i-1,j-1,word1,word2,dp)));
    }
    int tabulation(int n,int m,string word1, string word2,vector<vector<int>>& dp)
    {
        int i,j;
        //Base case
        for(i=0;i<=n;i++) dp[i][0]=i;
        for(j=0;j<=m;j++) dp[0][j]=j;
        //Bottom-Up 
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else              
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                                  //delete       //Insert    //Replace
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return minDis(n-1,m-1,word1,word2,dp);//TC->O(N*M) SC->O(N*M)+O(N+M)
        return tabulation(n,m,word1,word2,dp);//TC->O(N*M) SC->O(N*M)
    }
};