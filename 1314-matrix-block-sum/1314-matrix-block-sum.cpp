class Solution {
public:
    //TC->O(N*M) SC->O(N+M)+O(N+M)
    void calculatePrefixSum(vector<vector<int>>& preSum,vector<vector<int>>& mat,int n,int m)
    {
        int i,j;
        for(i=0;i<=m;i++)
            preSum[0][i] = 0;
        for(i=0;i<=n;i++)
            preSum[i][0] = 0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {     //cur value+prev row value+prev col value+common one in prev row and col
                preSum[i][j] = mat[i-1][j-1]+preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1];
            }
        }
        
    }
    int sumRegion(int r1,int c1,int r2,int c2,vector<vector<int>>& preSum)
    {
        r1++;c1++;r2++;c2++;
        return preSum[r2][c2]-preSum[r1-1][c2]-preSum[r2][c1-1]+preSum[r1-1][c1-1];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int i,j;
        vector<vector<int>>preSum(n+1,vector<int>(m+1,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        calculatePrefixSum(preSum,mat,n,m);
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int r1 = max(0,i-k);
                int c1 = max(0,j-k);
                int r2 = min(n-1,i+k);
                int c2 = min(m-1,j+k);
                ans[i][j]=sumRegion(r1,c1,r2,c2,preSum);
            }
        }
        return ans;
    }
};