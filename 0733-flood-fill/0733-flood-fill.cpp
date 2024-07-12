class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int inicol,int newcolor,int 
      delrow[],int delcol[],vector<vector<int>>& ans)
    {
        ans[sr][sc]=newcolor;
        int n = image.size();
        int m =image[0].size();
        for(int i=0;i<4;i++)
        {
            int nr = sr+delrow[i];
            int nc = sc+delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==inicol && ans[nr][nc]!=newcolor)
            {
                dfs(image,nr,nc,inicol,newcolor,delrow,delcol,ans);
            }
        }
    }
    //TC->O(N*M) SC->O(N*M)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int inicol = image[sr][sc];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(image,sr,sc,inicol,color,delrow,delcol,ans);
        return ans;
    }
};