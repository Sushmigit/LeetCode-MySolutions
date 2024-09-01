class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,m,n;
        n=matrix[0].size();m=matrix.size();
        int col0=1;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    //mark i th row
                    matrix[i][0]=0;
                   //mark j th col
                   if(j!=0)
                    matrix[0][j]=0;
                    else
                    col0=0;
                }
            }
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(j=0;j<n;j++)
            matrix[0][j]=0;
        }
        if(col0==0)
        {
            for(i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};