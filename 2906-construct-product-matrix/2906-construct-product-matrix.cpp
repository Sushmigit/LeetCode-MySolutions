class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int i;
        //TC->O(N*M) SC->O(N*M) 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>p(n,vector<int>(m,1));
        vector<int>pre(n*m,1),suf(n*m,1);
        for(i=1;i<n*m;i++)
        {
            int r = (i-1)/m,c=(i-1)%m;
            pre[i] = (pre[i-1]%12345)*(grid[r][c]%12345);
        }
        for(i=n*m-2;i>=0;i--)
        {
            int r = (i+1)/m,c=(i+1)%m;
            suf[i] = (suf[i+1]%12345)*(grid[r][c]%12345);
        }
        for(i=0;i<n*m;i++)
        {
            int r = i/m,c=i%m;
            p[r][c]=((pre[i]%12345)*(suf[i]%12345))%12345;
        }
        return p;
    }
};